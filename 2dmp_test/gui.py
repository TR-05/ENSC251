import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

# Read data from profile_output.txt
time_values = []
v_values = []
vl_values = []
vr_values = []

with open('profile_output.txt', 'r') as file:
    for line in file:
        t, v, vl, vr = map(float, line.strip().split(','))
        time_values.append(t)
        v_values.append(v)
        vl_values.append(vl)
        vr_values.append(vr)

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

# Plot v(t), vl(t), and vr(t) from profile_output.txt
ax1.plot(time_values, v_values, label='v(t)', color='blue')
ax1.plot(time_values, vl_values, label='vl(t)', color='green')
ax1.plot(time_values, vr_values, label='vr(t)', color='red')
ax1.set_xlabel('t')
ax1.set_ylabel('Velocity')
ax1.set_title('Velocity Profiles')
ax1.legend()

# Plot the data from path_output.txt
ax2.scatter(path_x_values, path_y_values)
ax2.set_xlabel('x')
ax2.set_ylabel('y')
ax2.set_title('Path Output Points')
plt.axis('square');
plt.tight_layout()
plt.show()