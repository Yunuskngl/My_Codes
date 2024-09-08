y1 = 1.05;  % alfa yerine y değerlerini tanımladım.
y2 = 1.05; 
y3 = 1.02; 
y4 = 0.80; 
y5 = 0.80;
y6 = 1.02;
y7 = 1.02;
y8 = 0.32;
y9 = 0.21;
y10 = 0.37;
y11 = 0.85;
y12 = 1.12;
y13 = 2.10;
y14 = 2.35;
y15 = 2.20;
y16 = 1.60;
y17 = 1.63;
y18 = 1.48;
y19 = 1.08;
y20 = 0.67;
y21 = 0.30;

x1 = 0;      % x değerlerini tanımladım
x2 = 4.4; 
x3 = 4.7;
x4 = 4.9; 
x5 = 7.2;
x6 = 7.3;    
x7 = 9.4;
x8 = 9.6;
x9 = 9.8;
x10 = 10.0;
x11 = 10.55;
x12 = 10.80;
x13 = 11.0;
x14 = 12.0;
x15 = 12.68;
x16 = 12.83;
x17 = 13.20;
x18 = 13.50;
x19 = 14.0;
x20 = 14.38;
x21 = 14.50;

y = [y1, y2, y3, y4, y5,y6,y7,y8,y9,y10, y11, y12, y13, y14, y15, y16, y17, y18, y19, y20, y21];  % y değerlerini bir vektörde topladım


x_breaks = [x1, x2, x3, x4, x5, x6, x7, x8, x9 , x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21];  % x değerlerini bir vektörde topladım

x = 0:0.01:15;    % x değerlerini 0 ile 15 arasında 0.01 artan şekilde tanımladım


Q1 = zeros(size(x));    % Q fonksiyonlarını tanımladım
Q2 = zeros(size(x));
Q3 = zeros(size(x));
Q4 = zeros(size(x));
Q5 = zeros(size(x));
Q6 = zeros(size(x));
Q7 = zeros(size(x));
Q8 = zeros(size(x));
Q9 = zeros(size(x));
Q10 = zeros(size(x));
Q11 = zeros(size(x));
Q12 = zeros(size(x));
Q13 = zeros(size(x));
Q14 = zeros(size(x));
Q15 = zeros(size(x));
Q16 = zeros(size(x));
Q17 = zeros(size(x));
Q18 = zeros(size(x));
Q19 = zeros(size(x));
Q20 = zeros(size(x));
Q21 = zeros(size(x));



Q1(x1 <= x & x < x2) = -0.227*x(x1 <= x & x < x2) + 1;    % Q fonksiyonlarına değerlerini tanımlıyorum.
Q1(x >= x2) = 0;

Q2(x1 <= x & x < x2) = 0.227*x(x1 <= x & x < x2);
Q2(x2 <= x & x < x3) = -3.333*x(x2 <= x & x < x3) + 15.667;
Q2(x >= x3) = 0;

Q3(x2 <= x & x < x3) = 3.333*x(x2 <= x & x < x3) - 14.667;
Q3(x3 <= x & x < x4) = -5*x(x3 <= x & x < x4) + 24.5;
Q3(x >= x4) = 0;

Q4(x3 <= x & x < x4) = 5*x(x3 <= x & x < x4) - 23.5;
Q4(x4 <= x & x < x5) = -0.435*x(x4 <= x & x < x5) + 3.130;
Q4(x >= x5) = 0;

Q5(x4 <= x & x < x5) = 0.435*x(x4 <= x & x < x5) - 2.130;
Q5(x5 <= x & x < x6) = -10*x(x5 <= x & x < x6) + 73;
Q5(x >= x6) = 0;

Q6(x5 <= x & x < x6) = 10*x(x5 <= x & x < x6) - 72;
Q6(x6 <= x & x < x7) = -0.476*x(x6 <= x & x < x7) + 4.476;
Q6(x >= x7) = 0;

Q7(x6 <= x & x < x7) = 0.476*x(x6 <= x & x < x7) - 3.476;
Q7(x7 <= x & x < x8) = -5*x (x7 <= x & x < x8) + 48;
Q7(x >= x8) = 0;

Q8(x7 <= x & x < x8) = 5*x(x7 <= x & x < x8) - 47;
Q8(x8 <= x & x < x9) = -5*x(x8 <= x & x < x9) + 49;
Q8(x >= x9) = 0;

Q9(x8 <= x & x < x9) = 5*x(x8 <= x & x < x9) - 48;
Q9(x9 <= x & x < x10) = -5*x(x9 <= x & x < x10) + 50;
Q9(x >= x10) = 0;

Q10(x9 <= x & x < x10) = 5*x(x9 <= x & x < x10) - 49;
Q10(x10 <= x & x < x11) = -1.818*x(x10 <= x & x < x11) + 19.182;
Q10(x >= x11) = 0;

Q11(x10 <= x & x < x11) = 1.818*x(x10 <= x & x < x11) - 18.182;
Q11(x11 <= x & x < x12) = -4*x(x11 <= x & x < x12) + 43.200;
Q11(x >= x12) = 0;

Q12(x11 <= x & x < x12) = 4*x(x11 <= x & x < x12) - 42.200;
Q12(x12 <= x & x < x13) = -5*x(x12 <= x & x < x13) + 55;
Q12(x >= x13) = 0;

Q13(x12 <= x & x < x13) = 5*x(x12 <= x & x < x13) - 54;
Q13(x13 <= x & x < x14) = -1*x(x13 <= x & x < x14) + 12;
Q13(x >= x14) = 0;

Q14(x13 <= x & x < x14) = 1*x(x13 <= x & x < x14) - 11;
Q14(x14 <= x & x < x15) = -1.471*x(x14 <= x & x < x15) + 18.647;
Q14(x >= x15) = 0;

Q15(x14 <= x & x < x15) = 1.471*x(x14 <= x & x < x15) - 17.647;
Q15(x15 <= x & x < x16) = -6.667*x(x15 <= x & x < x16) + 85.533;
Q15(x >= x16) = 0;

Q16(x15 <= x & x < x16) = 6.667*x(x15 <= x & x < x16) - 84.533;
Q16(x16 <= x & x < x17) = -2.703*x(x16 <= x & x < x17) + 35.676;
Q16(x >= x17) = 0;

Q17(x16 <= x & x < x17) = 2.703*x(x16 <= x & x < x17) - 34.676;
Q17(x17 <= x & x < x18) = -3.333*x(x17 <= x & x < x18) + 45;
Q17(x >= x18) = 0;

Q18(x17 <= x & x < x18) = 3.333*x(x17 <= x & x < x18) - 44;
Q18(x18 <= x & x < x19) = -2*x(x18 <= x & x < x19) + 28;
Q18(x >= x19) = 0;

Q19(x18 <= x & x < x19) = 2*x(x18 <= x & x < x19) - 27;
Q19(x19 <= x & x < x20) = -2.632*x(x19 <= x & x < x20) + 37.842;
Q19(x >= x20) = 0;

Q20(x19 <= x & x < x20) = 2.632*x(x19 <= x & x < x20) - 36.842;
Q20(x20 <= x & x < x21) = -8.333*x(x20 <= x & x < x21) + 120.833;
Q20(x >= x21) = 0;

Q21(x20 <= x & x < x21) = 8.333*x(x20 <= x & x < x21) - 119.833;
Q21(x21 <= x) = 0;

r = zeros(size(x));    % r fonksiyonlarını tanımlıyorum

r1 = Q1*y1 + Q2*y2;      % r fonksiyonlarına değerlerini tanımlıyorum.
r2 = Q2*y2 + Q3*y3;
r3 = Q3*y3 + Q4*y4;
r4 = Q4*y4 + Q5*y5;
r5 = Q5*y5 + Q6*y6;
r6 = Q6*y6 + Q7*y7;
r7 = Q7*y7 + Q8*y8;
r8 = Q8*y8 + Q9*y9;
r9 = Q9*y9 + Q10*y10;
r10 = Q10*y10 + Q11*y11;
r11 = Q11*y11 + Q12*y12;
r12 = Q12*y12 + Q13*y13;
r13 = Q13*y13 + Q14*y14;
r14 = Q14*y14 + Q15*y15;
r15 = Q15*y15 + Q16*y16;
r16 = Q16*y16 + Q17*y17;
r17 = Q17*y17 + Q18*y18;
r18 = Q18*y18 + Q19*y19;
r19 = Q19*y19 + Q20*y20;
r20 = Q20*y20 + Q21*y21;




%Bu döngü, x'in hangi aralıkta olduğunu belirler ve r fonksiyonunu hesaplar.
% Yani çizdirme işleminde ayrı ayrı r fonksiyonları yerine birleşik r fonksiyonları üretir
for i = 1:length(y) - 1     
    indices = x >= x_breaks(i) & x < x_breaks(i + 1);
    slope = (y(i + 1) - y(i)) / (x_breaks(i + 1) - x_breaks(i));
    r(indices) = slope * (x(indices) - x_breaks(i)) + y(i);
end

% Grafik çizimi
figure;  % yeni bir figür açar
plot(x, r, 'b');  % x ve r fonksiyonlarını çizer
xlabel('x');  % x eksenine isim verir
ylabel('r(x)'); % y eksenine isim verir
title('r(x) Fonksiyonu'); % grafiğe başlık ekler
grid on;  % ızgarayı açar
xlim([0 15]);   % x ekseninin sınırlarını belirler
ylim([0 15]);   % y ekseninin sınırlarını belirler

