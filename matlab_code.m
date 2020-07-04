%Trilateration point in 2D plane

%x=[4.0 9.0 9.0] x coordinates
%y=[4.0 7.0 1.0] y coordiantes
%r=[4.0 3.0 3.25] radii
%answer = 8.02,4.13

dataset = xlsread('prac.xlsx','A3:E5')

lq= dataset(:,3)
X = dataset(:,4)
Y = dataset(:,5)


for i=1:1:3
    %R(i)  = -3.949735 + 60.6861/(1 + (lq(i)/174.7853)^6.778297)
    R(i)  = -2.523772 + 58.322792/(1 + (lq(i)/174.281)^7.144644)


end;
    


A1=2*(X(1)-X(2))
B1=2*(Y(1)-Y(2))
C1=(X(1)^2+Y(1)^2-X(2)^2-Y(2)^2+R(2)^2-R(1)^2)

A2=2*(X(2)-X(3))
B2=2*(Y(2)-Y(3))
C2=(X(2)^2+Y(2)^2-X(3)^2-Y(3)^2+R(3)^2-R(2)^2)

x =(B1*C2 - B2*C1)/(A2*B1 - A1*B2)
y =(C1*A2 - C2*A1)/(A2*B1 - A1*B2)

theta = 0 : 0.01 : 2*pi;

p = R(1) * cos(theta) + X(1);
q = R(1) * sin(theta) + Y(1);

r = R(2) * cos(theta) + X(2);
s = R(2) * sin(theta) + Y(2);

t = R(3) * cos(theta) + X(3);
u = R(3) * sin(theta) + Y(3);
plot(p, q);
hold on
plot(r, s);
hold on
plot(t, u);
hold on
%for obtaining the practical position
plot(x,y,'.','MarkerSize',130,'Color','r');
hold on
axis square;
%xlim([16 36]);
%ylim([22 40]);
grid minor;
saveas(gcf,'Graph2.png')
