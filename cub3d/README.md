# cub3d

## Description

School 42's cub3d project is the implementation of a simple graphics engine that uses the miniLibX graphics library to render a 3D perspective environment based on a configuration file format. The project includes the use of raycasting techniques to simulate first-person perspective.

## Objectives.

1. **3D Visualization:**
   - Implement a graphics engine to visualize a 3D perspective environment.

2. **Configuration File Formatting:**
   - Use a configuration file to define the layout of the map, textures, colors, and other elements of the environment.

3. **Keyboarding:**
   - Allow the user to navigate the environment using the keys on the keyboard.

4. **Raycasting Techniques:**
   - Implement ray-casting techniques to compute the 3D representation of the scene.

5. **Wall detection:**
   - Detect collisions with walls and display the correct projection.

   ## How to use

### Clone repo and submodules

```sh
git clone --recurse-submodules https://github.com/tonyvillegas91/42-cursus.git
```

### Linux extra steps

- If you are using Linux, firts you will need to install a few dependencies

```sh
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

- Also, give execution permissions to the file `./lib/mlx_linux/configure`

```sh
chmod +x ./lib/mlx_linux/configure
```

## Compile

- Run `make` (make rules: `all`, `clean`, `fclean` and `re`)

```sh
make all clean
```

- Run `./cub3D` with a map as an argument (test maps on the `test_maps` folder)

```sh
./cub3D ./test_maps/labyrinth.cub
```