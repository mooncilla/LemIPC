/*
** lemipc.h for PSU_2016_lempipc
**
** Made by	gastal_r
** Login	gastal_r
**
** Started on	Sun Mar 26 12:30:19 2017 gastal_r
** Last update	Fri Mar 31 02:29:41 2017 gastal_r
*/

#ifndef     __LEMIPC_H__
# define    __LEMIPC_H__

# include   <sys/types.h>
# include   <sys/ipc.h>
# include   <sys/sem.h>
# include   <sys/shm.h>
# include   <sys/msg.h>
# include   <stdio.h>
# include   <string.h>
# include   <stdlib.h>
# include   <unistd.h>
# include   <time.h>
#include    <SFML/Graphics.h>

# define    EMPTY 0
# define    VIDEO_MOD {800, 800, 32}
# define    MAP_SIZE 250
# define    SPEED 5000

typedef struct      s_graph
{
  sfRectangleShape  *rect;
  sfRenderWindow    *win;
}                   t_graph;

typedef struct			s_msg
{
  long				mtype;
  char				str[32];
}				t_msg;

typedef struct			s_player
{
  int				x;
  int				y;
  int				team;
  int				id;
}				t_player;

typedef struct			s_shared
{
  int				players;
  int				teams;
  int				map[0];
}  __attribute__((packed))	t_shared;

typedef struct			s_struct
{
  key_t				key;
  int				semId;
  int				shmId;
  int				msgId;
  t_shared			*addr;
}				t_struct;

void	initNewPlayer(t_struct *, t_player *, int);
int	initFirstPlayer(t_struct *, int);
int	initValues(t_struct *, char *, int);
int	initOtherPlayers(t_struct *);
void	playerLoop(t_struct *, t_player *);
int	initMsg(t_struct *);
int	initSem(t_struct *);
void	initMap(t_struct *);
void	displayMap(int *, t_graph *);
int	printUsage();
int	checkAround(t_struct *, t_player, int);
void	semOperation(t_struct *, int );
void	i_die_msg(t_struct *, t_player *);
void	tryMoveLeft(t_struct *, t_player *, int);
void	tryMoveRight(t_struct *, t_player *, int);
void	tryMoveUp(t_struct *, t_player *, int);
void	tryMoveDown(t_struct *, t_player *, int);
int	findClosestAllies(t_struct *, t_player *, t_player *);
int	checkAroundAllies(t_struct *, t_player, int);
int	countEnemies(t_struct *, t_player, int);
int	getEnemyPosition(t_struct *, t_player, t_player *, int);
int	findClosestEnemy(t_struct *, t_player *, t_player *);
void	checkNewTeam(t_struct *, int);
void	move(t_struct *, t_player *);
void    timeDislayMap(t_struct *, t_graph *);
void		firstPlayerLoop(t_struct *, t_player *, t_graph *);
void  playerLoop(t_struct *, t_player *);

#endif