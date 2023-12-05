#include <so_long_bonus.h>

void animation(t_data *game)
{
	delete_images(game);
	if (game->anim_counter == 0)
		load_images_0(game);
	if (game->anim_counter == 1)
		load_images_1(game);
	if (game->anim_counter == 2)
		load_images_2(game);
}

void mini_window_tiling(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
				apply_image(game, game->wall_i, j, i);
			if (game->map[i][j] == 'P')
				apply_image(game, game->player_i, j, i);
			if (game->map[i][j] == 'E')
				apply_image(game, game->exit_i, j, i);
			if (game->map[i][j] == 'C')
				apply_image(game, game->collectable_i, j, i);
			if (game->map[i][j] == 'V' || game->map[i][j] == 'H')
				apply_image(game, game->enemy_i, j, i);
		}
	}
}
