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

% X1 zaman serisi
X1 = X(:,1);

% Gecikmeli gömme matrisi oluşturma
T = 9; % Gecikme zamanı
M = 3; % Gömme boyutu

N = length(X1);
embedded_X1 = zeros(N - (M - 1) * T, M);

for i = 1:M
    embedded_X1(:, i) = X1((M - i) * T + 1:end - (i - 1) * T);
end

% Faz uzayı grafiği (X1 için)
figure;
plot(embedded_X1(:,1), embedded_X1(:,2));
hold on;
plot(embedded_X1(:,1), embedded_X1(:,3)); % x1(t) ve x1(t+9) grafiği
xlim([-2.5, 2]); % x1 eksen aralığı
ylim([-2.5, 2]); % x2 ve x3 eksen aralığı
xlabel('x1(t)');
ylabel('x1(t-T)');
title('X1(t) ve X1(t+9) Faz Uzayı (2 Boyutlu)');
legend('x1(t)', 'x1(t+9)', 'Location', 'best');
grid on;
