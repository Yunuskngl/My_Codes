% Başlangıç koşulları ve parametreler
x1_0 = 1;
x2_0 = 1;
x3_0 = 0.1;
q = 15.2; % Değiştirildi

% Sabit noktaları bulma
options = optimset('Display','off'); % Fminsearch'ün çıktısını kapat
tolerance = 1e-6; % Tolerans

% Başlangıç tahminleri
initial_guesses = [
    x1_0, x2_0, x3_0;
    x1_0 + 0.1, x2_0 + 0.1, x3_0 + 0.1; % İkinci bir başlangıç noktası
    % Diğer başlangıç noktaları eklenebilir
];

% Sabit noktaları saklamak için boş bir dizi
fixed_points = zeros(size(initial_guesses));

% Lyapunov exponentlerini saklamak için boş bir dizi
lyapunov_exponents = zeros(size(initial_guesses, 1), 1);

for i = 1:size(initial_guesses, 1)
    initial_guess = initial_guesses(i, :);
    % Sabit noktaları bulma
    [~, X_fixed] = ode45(@(t, x) [
        x(2) * x(3);
        (x(3) - q) * x(1);
        (1 - sin(x(1))) * sin(x(2))
    ], [0, 1e5], initial_guess, options);
    last_point = X_fixed(end, :);
    % Hesaplanan sabit noktanın mevcut olanlardan uzak olup olmadığını kontrol etme
    distances = sqrt(sum((fixed_points - last_point).^2, 2));
    if all(distances > tolerance) % Eğer önceden bulunanlardan yeterince uzaksa
        fixed_points(i, :) = last_point; % Yeni sabit noktayı ekle
        
        % Jacobi matrisini hesaplama
        J = [
            0, last_point(3), last_point(2);
            (last_point(3) - q), 0, last_point(1);
            -cos(last_point(1)) * sin(last_point(2)), cos(last_point(1)) * cos(last_point(2)), 0
        ];
        
        % Jacobi matrisinin özdeğerlerini hesaplama
        eigenvalues = eig(J);
        
        % Lyapunov exponenti hesaplama
        lyapunov_exponents(i) = max(real(eigenvalues));
    end
end

% Bulunan sabit noktaları ve Lyapunov exponentlerini yazdırma
disp('Sabit Noktalar:');
disp(fixed_points);
disp('Lyapunov Exponentler:');
disp(lyapunov_exponents);

