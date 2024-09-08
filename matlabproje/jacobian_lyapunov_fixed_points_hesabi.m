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

% Jacobian matrisini saklamak için boş bir hücre dizisi
jacobian_matrices = cell(size(initial_guesses, 1), 1);

% Jacobian matrisini hesaplayan fonksiyon
function J = jacobian(x1, x2, x3, q)
    J = [
        0, x3, x2;
        (x3 - q), 0, x1;
        -cos(x1) * sin(x2), cos(x1) * cos(x2), 0
    ];
end

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
        
        % Jacobian matrisini hesaplama
        J = jacobian(last_point(1), last_point(2), last_point(3), q);
        
        % Jacobi matrisinin özdeğerlerini hesaplama
        eigenvalues = eig(J);
        
        % Lyapunov exponenti hesaplama
        lyapunov_exponents(i) = max(real(eigenvalues));
        
        % Jacobian matrisini saklama
        jacobian_matrices{i} = J;
    end
end

% Bulunan sabit noktaları, Jacobian matrislerini ve Lyapunov exponentlerini yazdırma
disp('Sabit Noktalar:');
disp(fixed_points);
disp('Jacobian Matrisleri:');
for i = 1:numel(jacobian_matrices)
    fprintf('Nokta %d:\n', i);
    disp(jacobian_matrices{i});
end
disp('Lyapunov Exponentler:');
disp(lyapunov_exponents);
