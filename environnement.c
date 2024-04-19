#include "main.h"
/**
 * environnement - Affiche les variables d'environnement
 *
 * Description : Cette fonction affiche les variables
 * d'environnement actuellement
 * disponibles dans le programme. Elle parcourt le tableau
 * d'environnement `environ`
 * jusqu'à ce qu'elle rencontre un pointeur NULL, puis affiche
 * chaque chaîne de caractères
 * correspondant à une variable d'environnement.
 */
void environnement(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
