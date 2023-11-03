% Create two lists of data
x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15. 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80]
y = [408, 455, 617, 635, 636, 634, 630, 576, 533, 480, 342, 266, 215, 182, 163, 142, 130, 117, 109, 97, 93, 88, 84, 76]

% Plot the data
plot(x, y);

% Add labels and a title to the plot
xlabel('Distance (cm)');
ylabel('ACD Measurement');
title('Measured Data');

% Add a legend if needed
legend('Calibration Curve');

% Customize the plot, if desired
grid on;  % Add grid lines
