<div align="center">
    <img src="https://github.com/15Galan/42_project-readmes/blob/master/banners/cursus/projects/so_long-light.png?raw=true#gh-light-mode-only" alt="Banner (claro)" />
    <img src="https://github.com/15Galan/42_project-readmes/blob/master/banners/cursus/projects/so_long-dark.png?raw=true#gh-dark-mode-only" alt="Banner (oscuro)" />
    <br>
    This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements
    <br>
    <a href='https://profile.intra.42.fr/users/alvega-g' target="_blank">
        <img alt='42 (oscuro)' src='https://img.shields.io/badge/Málaga-black?style=flat&logo=42&logoColor=white'/>
    </a>
    <img src="https://img.shields.io/badge/score- 125%20%2F%20100-success?color=%2312bab9&style=flat" />
</div>

---
<div>
	<img src="https://s13.gifyu.com/images/SjJBu.gif"/>
</div>
# Mandatory part

<table>
  <tr>
    <th>Program name</th>
    <td><em>so_long</em></td>
  </tr>
  <tr>
    <th>Turn in files</th>
    <td>Makefile, <code>*.h</code>, <code>*.c</code>, maps, textures</td>
  </tr>
  <tr>
	<th>Makefile</th>
	<td><em>NAME</em>, <em>all</em>, <em>clean</em>, <em>fclean</em>, <em>re</em></td>
  </tr>
  <tr>
    <th>Arguments</th>
    <td>A map in format <code>*.ber</code></td>
  </tr>
  <tr>
    <th>External functions</th>
    <td> <code>open, close, read, write, malloc, free, perror, strerror, exit</code><br>
	All functions of the math library (-lm compiler option, man man 3 math)><br>
	All functions of the MiniLibx (or MLX42)<br>
	<code>ft_printf</code> and any equivalent YOU coded</td>
  </tr>
  <tr>
	<th>Libft authorized</th>
	<td>Yes</td>
  </td>
  <tr>
    <th>Description</th>
    <td>You must create a basic 2D game in which a dolphin escapes Earth after eating some fish. Instead of a dolphin, fish, and the Earth, you can use any character, any collectible and any place you want.
</td>
  </tr>
</table>

## Observations

Your project must comply with the following rules:
- You __must__ use the ``MiniLibX`` (or ``MLX42``). Either the version available on the school machines,
or installing it using its sources.
- You have to turn in a _Makefile_ which will compile your source files. It must not
relink.
- Your program has to take as parameter a map description file ending with the ``.ber``
extension.

## Game

 The player’s goal is to collect every collectible present on the map, then escape
chosing the shortest possible route.
- The W, A, S, and D keys must be used to move the main character. You can also use ZQSD or the arrow keys.
- The player should be able to move in these __4 directions__: up, down, left, right.
- The player should not be able to move into walls.
- At every move, the current __number of movements__ must be displayed in the shell.
- You have to use a __2D view__ (top-down or profile).
- The game doesn’t have to be real time.
- Although the given examples show a dolphin theme, you can create the world you
want.

## Graphic management

- Your program has to display the image in a window.
- The management of your window must remain smooth (changing to another window, minimizing, and so forth).
- Pressing __ESC__ must close the window and quit the program in a clean way.
- Clicking on the cross on the window’s frame must close the window and quit the
program in a clean way.
- The use of the __images__ of the ``MiniLibX`` is mandatory.

## Map

 The map has to be constructed with 3 components: __walls__, __collectibles__, and __free
space__.
- The map can be composed of only these 5 characters:<br>
0 for an empty space,<br>
1 for a wall,<br>
C for a collectible,<br>
E for a map exit,<br>
P for the player’s starting position.

Here is a simple valid map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```	

- The map must contain __1 exit__, at least __1 collectible__, and __1 starting position__ to
be valid.
- The map must be rectangular.
- The map must be closed/surrounded by walls. If it’s not, the program must return
an error.
- You have to check if there’s a valid path in the map.
- You must be able to parse any kind of map, as long as it respects the above rules.
- Another example of a minimal ``.ber`` map:
```	
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```
- If any misconfiguration of any kind is encountered in the file, the program must
exit in a clean way, and return "Error\n" followed by an explicit error message of
your choice.

# Bonus part

Usually, you would be encouraged to develop your own original extra features. However,
there will be much more interesting graphic projects later. They are waiting for you!!
Don’t lose too much time on this assignment!

You are allowed to use other functions to complete the bonus part as long as their
use is __justified__ during your evaluation. Be smart!

You will get extra points if you:
- Make the player lose when they touch an enemy patrol.
- Add some sprite animation.
- Display the movement count directly on screen instead of writing it in the shell.