# FdF

## Description

School 42's FdF project is a 3D graphical map viewer that uses the school's graphics library, such as mlx. The program reads data from a file containing information about the height of points on a map and creates a 3D visual representation using lines connecting these points.

## Objectives.

1. **Graphical Interface:**
   - Create a graphical interface using the school's graphical library (mlx).

2. **Reading Data:**
   - Read a data file to obtain information about the height of points on the map.

3. **Projections:**
   - Implement at least two projections (isometric and orthographic) to visualize the map in 3D.

4. **Colors:**
   - Assign colors to the lines according to the height of the points to improve visual readability.

5. **User Controls:** 
    - Allow user interaction, such as adjusting the height or rotating the points.

# How to use

## Clone repo and submodules

```sh
git clone --recurse-submodules https://github.com/izenynn/fdf.git
```

## Linux extra steps

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

- Run `./fdf` with a map as an argument (test maps on the `test_maps` folder)

```sh
./fdf ./test_map/42.fdf
```