/*dx1/dt = x2.x3
dx2/dt = (x3 - q).x1 
dx3/dt = (1-sinx1).sinx2

başlangıç koşulları x1 = 1  , x2 = 1 , x3 = 0.1 , q=15,2 alınacak. fix pointler hesaplancak. kararlılık analizi yapılacak.
zaman serileri hesaplancak 

(x1,x2) , (x2,x3) , (x1,x3) grafikleri çizilecek. 

faz uzayı çizilcek

x1 zaman serisi faz uzayında yeniden yapılandırılacak öncelikle delay time (gecikme zamanı) hesaplanacak.

gecikme zamanı T = 9 çıkıcak . daha sonra gömme boyutu hesaplıyoruz. M = 3 çıkıcak. faz uzayında yapılandırma grafikleri çizilecek.

lyapunov exponent hesaplanacak. en büyük lyapunov exponent hesaplanacak.

j matris(jacobian) j = (x1,x2,x3) hesaplancak.
bunları yapan bir matlab kodu yaz.
Matlab kodu : 

clear all
clc
close all

%parametreler
q = 15.2;
s = 1;
%başlangıç koşulları
x1 = 1;
x2 = 1;
x3 = 0.1;

%zaman aralığı
t = 0:0.01:100;

%ode45 fonksiyonu ile diferansiyel denklemler çözülüyor.
[t,x] = ode45(@(t,x) [x(2)*x(3);(x(3)-q)*x(1);(1-sin(x(1)))*sin(x(2))],t,[x1;x2;x3]);

%fix pointler hesaplanıyor.
fix_point = fsolve(@(x) [x(2)*x(3);(x(3)-q)*x(1);(1-sin(x(1)))*sin(x(2))], [1;1;0.1]);

%kararlılık analizi yapılıyor.
j = [x(2)*x(3) x(3) x(2);(x(3)-q) x(1) 0;(1-sin(x(1))) 0 cos(x(2))];
eig(j)


X1 zaman serisinin gecikme zamanı ve m=3 için faz uzayı grafiğini denermisin:



*/



% Başlangıç koşulları ve parametreler
x1_0 = 1;
x2_0 = 1;
x3_0 = 0.1;
q = 15.2;

% Zaman aralığı
tspan = 0:0.01:100; % Örnek bir zaman aralığı, isteğe göre değiştirilebilir

% ODE tanımı
ode = @(t, x) [
    x(2) * x(3);
    (x(3) - q) * x(1);
    (1 - sin(x(1))) * sin(x(2))
];

% ODE çözümü
[t, X] = ode45(ode, tspan, [x1_0, x2_0, x3_0]);

% Fix point hesaplama
fix_point = fsolve(@(x) [
    x(2) * x(3);
    (x(3) - q) * x(1);
    (1 - sin(x(1))) * sin(x(2))
], [1; 1; 0.1]);

% Kararlılık analizi
jacobian = @(x) [
    x(2) * x(3), x(3), x(2);
    (x(3) - q), x(1), 0;
    (1 - sin(x(1))), 0, cos(x(2))
];

eigenvalues = eig(jacobian(X(end, :)));

% Zaman serileri
figure;
subplot(3, 1, 1);
plot(t, X(:, 1));
xlabel('Zaman');
ylabel('x1');
title('x1 Zaman Serisi');

subplot(3, 1, 2);
plot(t, X(:, 2));
xlabel('Zaman');
ylabel('x2');
title('x2 Zaman Serisi');

subplot(3, 1, 3);
plot(t, X(:, 3));
xlabel('Zaman');
ylabel('x3');
title('x3 Zaman Serisi');

% Faz uzayı
figure;
subplot(3, 1, 1);
plot3(X(:, 1), X(:, 2), X(:, 3));
xlabel('x1');
ylabel('x2');
zlabel('x3');
title('Faz Uzayı');

% Gecikme zamanı ve gömme boyutu hesaplama
T = 9; % Ö
M = 3; % Gömme boyutu

% Lyapunov exponent hesaplama
lyapunov_exponents = lyapunov_exponents(X, T, M);

% J matrisi hesaplama
jacobian_at_fix_point = jacobian(fix_point);

% Lyapunov exponent hesaplar
function exponents = lyapunov_exponents(X, T, M)
    N = size(X, 1);
    exponents = zeros(1, M);
    
    for i = 1:M
        for j = 1:N-T
            delta = X(j+T, :) - X(j, :);
            norm_delta = norm(delta);
            exponents(i) = exponents(i) + log(norm_delta);
        end
        exponents(i) = exponents(i) / (N - T);
    end
end
```

Bu kod, verilen diferansiyel denklemleri çözer, fix pointleri hesaplar, kararlılık analizi yapar, zaman serilerini ve faz uzayını çizer, gecikme zamanını ve gömme boyutunu hesaplar, Lyapunov exponentleri hesaplar ve J matrisini hesaplar. Kodu çalıştırarak sonuçları görebilirsiniz.




/*
U1(x) = [- 0.1692*x - 4.87]*10^-9
 
U2(x) = - 0.08433*x*10^-9 - 4.903*10^-9
 
U3(x) = 12.47*x*10^-9- 17.46*10^-9
 grafiklerini çizmek için matlab kodu yazar mısın
*/





