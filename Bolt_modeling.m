%************************************************************************
%程序名:Bolt_modeling.m
%程序用于建立标准螺栓外螺纹的精细模型(支持任意长度的螺纹建模)
%螺栓含有退刀槽(退刀槽位于Z轴负半轴,长度为一个退刀槽螺距)
%************************************************************************
clear,clc
%********************************建模参数输入******************************
d=12;               %螺栓的公称直径
r_exter=6;          %有限元模型外径(和螺栓的公称直径对应)
r_inter=4;          %有限元模型内径
P=1.75;             %螺距
P_groove=1;         %退刀槽螺距
Rho=0.13*P;         %牙型半径

H=sqrt(3)/2*P;
Theta1=pi/8;
Theta2=(1-sqrt(3)/P*Rho)*pi;
Theta3=(1+sqrt(3)/P*Rho)*pi;
Theta4=15/8*pi;
%**************************************************************************

%*************************绘制外螺纹轮廓线*********************************
theta_plot=linspace(0,2*pi,1001)';    %极坐标的角度样点
%绘制公称直径线
x_plot=d/2*cos(theta_plot);
y_plot=d/2*sin(theta_plot);
figure;plot(x_plot,y_plot,'--','LineWidth',1);axis equal;hold on;
%绘制外螺纹轮廓线
r_plot=zeros(1001,1);                  %极坐标的半径样点
for i=1:1001
    if (theta_plot(i)>=0)&&(theta_plot(i)<=Theta1)
        r_plot(i)=d/2;
    elseif (theta_plot(i)>=Theta1)&&(theta_plot(i)<=Theta2)
        r_plot(i)=d/2+H/8-H/pi*theta_plot(i);
    elseif (theta_plot(i)>=Theta2)&&(theta_plot(i)<=pi)
        r_plot(i)=d/2-7/8*H+2*Rho-...
            sqrt(Rho^2-(pi-theta_plot(i))^2/(4*pi^2)*P^2);
    elseif (theta_plot(i)>=pi)&&(theta_plot(i)<=Theta3)
        r_plot(i)=d/2-7/8*H+2*Rho-...
            sqrt(Rho^2-(theta_plot(i)-pi)^2/(4*pi^2)*P^2);
    elseif (theta_plot(i)>=Theta3)&&(theta_plot(i)<=Theta4)
        r_plot(i)=d/2-15/8*H+theta_plot(i)/pi*H;
    else
        r_plot(i)=d/2;
    end
end
x_plot=r_plot.*cos(theta_plot);
y_plot=r_plot.*sin(theta_plot);
plot(x_plot,y_plot,'r','LineWidth',2);hold off;
legend('公称直径','外螺纹轮廓线');title('外螺纹轮廓线示意图');
figure
plot(r_plot,theta_plot/(2*pi)*P,'r','LineWidth',2);axis equal;
title('沿螺栓中心轴线的螺纹截面');
%**************************************************************************

%****************************处理有限元网格节点****************************
%读取初始网格节点
Mesh_Data=importdata('MESH.txt');
Node_num=size(Mesh_Data,1);             %网格总节点数
%绘制初始网格节点分布
figure;
scatter3(Mesh_Data(:,2),Mesh_Data(:,3),Mesh_Data(:,4));
%逐节点循环修改节点坐标
Mesh_Data_Modified=zeros(Node_num,4);   %用于存放修改之后的节点坐标
for i=1:Node_num
    %读取初始网格节点坐标
    Coord_X=Mesh_Data(i,2);             %X坐标
    Coord_Y=Mesh_Data(i,3);             %Y坐标
    Coord_Z=Mesh_Data(i,4);             %Z坐标
    %计算节点在对应螺纹截面的角度(假定螺纹截面位于XOY平面)
    if Coord_X>=0&&Coord_Y>=0            %节点位于截面的第一象限
        theta_ini=atan(Coord_Y/Coord_X);
    elseif Coord_X<0&&Coord_Y>=0         %节点位于截面的第二象限
        theta_ini=pi+atan(Coord_Y/Coord_X);
    elseif Coord_X<0&&Coord_Y<0          %节点位于截面的第三象限
        theta_ini=pi+atan(Coord_Y/Coord_X);                  
    else                                %节点位于截面的第四象限
        theta_ini=2*pi+atan(Coord_Y/Coord_X);
    end
    %计算由于螺纹截面高度变化引起的节点角度增量
    theta_add=2*pi*(Coord_Z/P);
    %计算节点真实的角度
    theta=theta_ini+theta_add;
    theta=mod(theta,2*pi);       %角度超过2pi后需要进行取余运算
    
    %计算最外层节点修改后的径向坐标
    if Coord_Z>=0    %节点位于正常螺纹部分
        if (theta>=0)&&(theta<=Theta1)
            r=d/2;
        elseif (theta>=Theta1)&&(theta<=Theta2)
            r=d/2+H/8-H/pi*theta;
        elseif (theta>=Theta2)&&(theta<=pi)
            r=d/2-7/8*H+2*Rho-...
                sqrt(Rho^2-(pi-theta)^2/(4*pi^2)*P^2);
        elseif (theta>=pi)&&(theta<=Theta3)
            r=d/2-7/8*H+2*Rho-...
                sqrt(Rho^2-(theta-pi)^2/(4*pi^2)*P^2);
        elseif (theta>=Theta3)&&(theta<=Theta4)
            r=d/2-15/8*H+theta/pi*H;
        else
            r=d/2;
        end
    else            %节点位于退刀槽部分
        %计算Z=0位置处的螺纹线
        if (theta_ini>=0)&&(theta_ini<=Theta1)
            r_ini=d/2;
        elseif (theta_ini>=Theta1)&&(theta_ini<=Theta2)
            r_ini=d/2+H/8-H/pi*theta_ini;
        elseif (theta_ini>=Theta2)&&(theta_ini<=pi)
            r_ini=d/2-7/8*H+2*Rho-...
                sqrt(Rho^2-(pi-theta_ini)^2/(4*pi^2)*P^2);
        elseif (theta_ini>=pi)&&(theta_ini<=Theta3)
            r_ini=d/2-7/8*H+2*Rho-...
                sqrt(Rho^2-(theta_ini-pi)^2/(4*pi^2)*P^2);
        elseif (theta_ini>=Theta3)&&(theta_ini<=Theta4)
            r_ini=d/2-15/8*H+theta_ini/pi*H;
        else
            r_ini=d/2;
        end
        %根据Z=0处的螺纹线线性插值得到退刀槽对应的螺纹线
        if abs(Coord_Z)<=P_groove    %仅在一个退刀槽长度内更改网格节点
            r=(d/2-r_ini)/P_groove*abs(Coord_Z)+r_ini;
        else
            r=d/2;                   %超出退刀槽长度的网格保持不变
        end
    end
    
    %计算未修改节点到原点的径向距离
    r_dist=sqrt(Coord_X^2+Coord_Y^2); 
    %计算内层网格到原点的真实径向距离(线性插值)
    r=(r_dist-r_inter)/(r_exter-r_inter)*(r-r_inter)+r_inter;     
    %根据节点的径向坐标和角坐标计算笛卡尔坐标
    Coord_X_Modified=r*cos(theta_ini);
    Coord_Y_Modified=r*sin(theta_ini);
    %存放修改后的节点信息到新的矩阵
    Mesh_Data_Modified(i,1)=Mesh_Data(i,1);
    Mesh_Data_Modified(i,2)=Coord_X_Modified;
    Mesh_Data_Modified(i,3)=Coord_Y_Modified;
    Mesh_Data_Modified(i,4)=Coord_Z;    
end
%绘制修改之后的网格节点分布
figure;
scatter3(Mesh_Data_Modified(:,2),Mesh_Data_Modified(:,3),...
    Mesh_Data_Modified(:,4));
axis equal;hold on;
scatter3(d/2*cos(theta_plot),d/2*sin(theta_plot),zeros(1001,1));
%**************************************************************************

%************************修改后的网格节点信息输出**************************
fileID=fopen('MESH_DATA_Modified.txt','w');
for i=1:Node_num
    fprintf(fileID,'%8d,',Mesh_Data_Modified(i,1));          %节点编号
    fprintf(fileID,'%20.15g,',Mesh_Data_Modified(i,2));      %X坐标
    fprintf(fileID,'%20.15g,',Mesh_Data_Modified(i,3));      %Y坐标
    fprintf(fileID,'%20.15g\n',Mesh_Data_Modified(i,4));     %Z坐标
end
fclose(fileID);
%**************************************************************************