
/*nous allons avoir besoin d'un char * d'un static t_list et d'un int 
	qui nous servira pour le retour de read et pour un malloc.
	dans un if gerer les 3 points suivant : pensez a gerer si l'open de fd ne marche pas sachant
	que open renvoie un negatif si c'est le cas ou
	si l'utilisateur definie un bufferzize negatif ou egal a 0 ou
	si le read fonctionne avec read(fd, &line, 0) < 0).
	initialiser line a NULL;
	1. appel de read_stack ou on envoie le fd eet l'adresse de stack;
		une foit read_stack fini au retour il faut verifier si stack est NULL et retrun NULL;
	2. appel d'extract line on lui envoie stack"sans * car on ne va pas modifier le content de stack. 
		et l'adresse de line; 
	3. appel de clean_stack a qui on envoie l'adresse de stack car on va modifier son content
		donc on le recoit en **.
	au retour de clean_stack on verifie si le premier element de line et == a 0
		on free stack puis reinitialise stack a NULL.
		on free line puis return NULL;
	et enfin on return line;*/
char *get_next_line(int fd)
{
	
}

/* 1.cette fonction sert a lire le fd a l'aide d'une boucle qui va iterer tant que \n n'est pas trouver
		et que r_read et different de 0 donc ne pas oublier d'initialiser r_dead a 1.
		ensuite il faut malloc notre buffer a taille de buffer_size.
		puis faire en sorte que notre r_read soit egal au retour de (int)read qui prendra en parametre 
		fd buffer et buffer_size.
	   2.si notre pointeur sur stack est NULL et que notre r_dead egal 0 ou -1 
	   		alors free le buffer et return; car le r_read est egal au retour de read ne l'oublions pas.
	   3.enfin ne pas oublier le 0 a la fin de buff à l'aide de r_dead
	   		qui a maintenant la valeur equivalante a la fin de notre buffer.
	   		appel de go_to_stack qui prend en parametre stack buffer et r-read;
	   		puis free buffer.*/
void	read_stack(int fd, t_list **stack)
{


}

/* 1.ici nous allons ajouter notre buffer a la stack pour ca 
		il va nous falloire 2 pointeur t_list et un index.
		le premier t_liste servira a mettre le buffer dedans car l'enjeu ici est de ne pas perdre l'adresse
		du premier element de stack, nous devrons donc le malloc puis
		initialiser son next a NULL ne jamais oublier ca.
		ensuite ne surtout pas oublier de malloc son content a l'aide de r_read ici encore car
		il a la valeur de retour de read. ne pas oublier les return NULL des 2 malloc si cela ce passe mal.
  2.ensuite a l'aide d'une boucle qui itere tant que la fin de buffer n'est pas atteint et que notre index 
		et plus petit que r_dead afin d'avoir tout le contenue du buffer dans notre t_list temporaire.
		nous remplissons le contenue de cette t_list temp avec le buffer.
		en sortis de boucle on oublie pas le petit 0 au bout de notre contenue.
  3.a partir d'ici il existe 2 possibilité soit notre stack est NULL car on a encore jamais iterer dedans
  		et donc notre pointeur de stack devra pointé vers notre t_list temp et on return.
  		sinon notre 2 eme t_list  last crée precedement devra pointé sur le dernier element de notre stack.
  		a l'aide de lst_getlast.
  		pour enfin passer a la prochaine list de notre 2 eme t_list last et la faire pointé sur notre premiere.
  		(c'est tricky car en faite en fesant pointer last sur le dernier element de stack nous sommes a la fin de stack
  		et en fesant ensuite avancer last a sa prochaine list nous sommes sur la parochaine list de stack 
  		que nous fesons pointer vers notre t_list qui contient le buffer nous avons donc ajouter le buffer a stack sans*
  		avoir avancer dans stack)*/
void	go_to_stack(t_list **stack, char *buffer, int r_read)
{

}

/* 1.ici nous allons iterer le contenue de stack dans line que nous recevons en parametre en tant que **line.
		attention a la gestion d'erreur si stack est NULL ou si *line est NULL.
		appel de generate line qui va nous malloc line a la bonne taille et qui prend en parametre 
		line et stack.
   2.nous aurons besoin de 2 index ainsi que 2 boucle imbriqué.
		la premiere boucle parcours stack jusqua 0.
		la seconde parcours le contenue de stack et si le contenue de stack et egal a \n
		nous remplissons le pointeur sur line de j avec le contenue de stack en l'occurence \n.
		puis break.
		sinon nous remplissons le pointeur de line de j avec le contenue de stack ++;
		en sortit de boucle 2 nous passons a la chaine suivante de stack.
	3. en sortit de boucle 1 pensez a ajouter le /0 a la fin du pointeur de line de j.*/

char *extract_line(t_list *stack)
{

}

/* le but ici et de decouper le dernier buffer qui contien le \n et le debut de la ligne suivante et
	d'ajouter a la fin de stack ce qui precede \n pour ensuite sauvegarder ce qui suis \n dans un pointeur de type t_list
	qui repointera vers stack une fois le free de stack effectué.
	
	1. nous avons besoin de 2 pointeur de type t_list ainsi que 2 index.
		le premier pointeur doit être malloc de la taile t_list.
		il faut gerer le cas ou stack est NULL ou le cas du malloc NULL.
		initialiser le pointeur suivant malloc precedement a NULL.
		le 2 eme pointeur last doit pointer sur le dernier élément de pointeur de stack.(lst_getlast).
	2. nous avons besoin d'une boucle qui itere jusqu'au bout du contenue de last et tant que le contenue
	 	de last est different de \n , nous incrementons.
		en sortis de boucle si le contenue de last est egal a 0 et que le contenue de last indexe et egal a \n
	 	on incremente.
	3. on malloc le contenue du premier pointeur malloc precedement a l'aide de strlen(contenue de last) - i.
		ps(pour n'avoir que ce qui suis le \n de notre dernier buffer).
		gestion du malloc null.
	4. nous avons besoin d'une boucle qui itere jusquau bout du contenue de last.
		avec le 2 eme index le contenue du pointeur malloc devra être remplit avec le contenue de last.
		en sortis de boucle on ajoute le \0 a notre pointeur malloc.
		on appel la fonction free_stack qui prend en parametre un pointeur de stack.
		et pour finir on fait pointer le pointeur de stack sur le pointeur malloc precedement pour
		enfin passer a la ligne suivante et tout recommencer.

void	clean_stash(t_list **stash)
{

}

/*----------------------------------------------------------------------------*/

/* 1.nous aurons besoin ici d'un pointeur sur list qui pointera sur stack.
   2.il nous faudra une boucle qui va iterer tant que nous ne sommes pas au bout de notre pointeur sur list temp
   		et tant qu'il reste des élément suivant a ce même pointeur.
   		nous passons a l'élément suivant.
   	3. nous retournons le pointeur.
   		ps(le pointeur nous permet de parcourir stack sans avancer dans stack car pensez bien
   		que revenir en arriere sur une list chainer est impossible).*/

t_list	*lst_getlast(t_list *stack)
{

}

/* 1. nous aurons besoin ici d'un index et d'un pointeur sur stack qui pointera sur le dernier
		élément de stack(lst_getlast).
		pensez bien a la gestion du cas ou stach est NULL.
   2. nous aurons besoin d'une boucle qui itere jusqu'a la fin du contenue de notre pointeur sur chaine.
   		si le contenue de notre pointeur est egal a un \n nous retournons 1.
   		sinon on avance.
   3. return 0 en sortit de fonction si aucun \n est trouvé.
   ps(car le tout dernier buffer du texte ne contiendra pas de \n et donc la fonction retournera 0);*/

int	chearch_endline(t_list *stach)
{

}

/* cette fonction a pour but de malloc line a la bonne taille.
	1. nous auront besoin d'un int len et d'un index.
	2. nous auraont besoin de 2 boucle imbriqué , la premiere va iterer jusqu'au bout de stack.
		la seconde ietere sur le contenue de stack.
		 si un \n est trouvé nous incrementons len et nous breakons.
		en sortit de if  nous incrementons len et l'index car le \n n'est pas encore trouvé.
	3. une foit le \n trouvé en sortis de boucle nous passons à l'élément suivant de stack et on recommence la boucle.
	4. on malloc le pointeur sur line a l'aide de len.*/		 

void	generate_line(char **line, t_list *stash)
{

}

/* free stack comme son nom l'indique nous sert ici a free stack tout en gardant de coté l'adresse du premier élément de stack.
	1. nous avons donc besoin de 2 pointeur de type t_list un temp et un next.
		le pointeur temp doit pointer sur stack.
	2. nous avons besoin d'une boucle qui itere jusqu'au bout de temp.
		on free le contenue de temp , on passe à l'élément suivant de temp.
		on free temp et on passe au temp suivant.
	3. fin

void	free_stash(t_list *stash)
{

}

size_t	ft_strlen(const char *s)
{

}
