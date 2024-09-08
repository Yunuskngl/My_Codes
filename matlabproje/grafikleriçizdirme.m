% MATLAB kodu

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

% Zaman serileri
figure;
subplot(3,1,1);
plot(t, X(:,1));
xlabel('Zaman');
ylabel('x1');
title('x1 Zaman Serisi');

subplot(3,1,2);
plot(t, X(:,2));
xlabel('Zaman');
ylabel('x2');
title('x2 Zaman Serisi');

subplot(3,1,3);
plot(t, X(:,3));
xlabel('Zaman');
ylabel('x3');
title('x3 Zaman Serisi');

% Grafikler
figure;
subplot(3,1,1);
plot(X(:,1), X(:,2));
xlabel('x1');
ylabel('x2');
title('x1-x2 Grafikleri');

subplot(3,1,2);
plot(X(:,2), X(:,3));
xlabel('x2');
ylabel('x3');
title('x2-x3 Grafikleri');

subplot(3,1,3);
plot(X(:,1), X(:,3));
xlabel('x1');
ylabel('x3');
title('x1-x3 Grafikleri');

% Faz uzayı analizi
% Faz uzayı grafiği
figure;
plot3(X(:,1), X(:,2), X(:,3));
xlabel('x1');
ylabel('x2');
zlabel('x3');
title('Faz Uzayı');

% Delay embedding analizi
T = 9; % Gecikme zamanı
M = 3; % Gömme boyutu
embedded_data = delayEmbedding(X(:,1:3), T, M); % Gecikmeli gömme

% Lyapunov exponent hesabı
[~, exponents] = lyapunovExponents(embedded_data);

% Jacobian matrisi hesabı
jacobian = computeJacobian(X(:,1:3), ode);

% Lyapunov exponentlerini yazdırma
disp('Lyapunov Exponents:');
disp(exponents);

% Jacobian matrisini yazdırma
disp('Jacobian Matrix:');
disp(jacobian);