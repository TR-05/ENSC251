import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Read the data from the text file
def read_data(filename):
    with open(filename, 'r') as file:
        lines = file.readlines()
    data = []
    for line in lines:
        t, v = map(float, line.strip().split(','))
        data.append((t, v))
    return data

# Update the position of the box
def update(frame, data, box, positions, ax):
    if frame == 0:
        positions[frame] = 0
    else:
        t, v = data[frame]
        prev_t = data[frame - 1][0]
        positions[frame] = positions[frame - 1] + v * (t - prev_t)
    box.set_x(positions[frame])
    ax.set_title(f'Frame: {frame}, Position: {positions[frame]:.3f}')
    return box,

# Main function to create the animation
def animate_box(filename):
    data = read_data(filename)
    positions = [0] * len(data)
    
    fig, ax = plt.subplots()
    ax.set_xlim(-10, 10)
    ax.set_ylim(0, 10)
    
    box = plt.Rectangle((0, 5), 1, 1, fc='blue')
    ax.add_patch(box)
    
    # Add a vertical line at x=0
    ax.axvline(x=0, color='red', linestyle='--')
    
    ani = animation.FuncAnimation(fig, update, frames=len(data), fargs=(data, box, positions, ax), interval=10, repeat=True)
    plt.show()

# Call the function with the filename
animate_box('data.txt')