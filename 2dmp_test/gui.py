import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

# Read data from profile_output.txt
profile_x_values = []
profile_y_values = []

with open('profile_output.txt', 'r') as file:
    for line in file:
        x, y = map(float, line.strip().split(','))
        profile_x_values.append(x)
        profile_y_values.append(y)

# Read data from path_output.txt
path_x_values = []
path_y_values = []

with open('path_output.txt', 'r') as file:
    for line in file:
        x, y = map(float, line.strip().split(','))
        path_x_values.append(x)
        path_y_values.append(y)

# Create subplots
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 6))

# Plot the data from profile_output.txt
ax1.scatter(profile_x_values, profile_y_values)
ax1.set_xlabel('t')
ax1.set_ylabel('v')
ax1.set_title('Profile Output Points')

# Plot the data from path_output.txt
ax2.scatter(path_x_values, path_y_values)
ax2.set_xlabel('x')
ax2.set_ylabel('y')
ax2.set_title('Path Output Points')

plt.tight_layout()
plt.show()