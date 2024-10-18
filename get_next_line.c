/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:53:48 by maiferna          #+#    #+#             */
/*   Updated: 2024/10/14 13:54:04 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Esta función se encargará de leer del archivo. 
Leerá datos en bloques desde el descriptor de archivo hasta que encuentre un salto de línea (\n) 
o llegue al final del archivo. Debería leer datos del archivo y gestionar stash*/

char	*ft_read_line(int fd, char *stash)
{
	char	*read_line;
	char	*temp;
}

/* Esta función construirá la línea a partir de los datos leídos. 
Manejará la concatenación y la gestión de la memoria. Debería actualizar stash con los datos no utilizados*/

char	*ft_set_line(char *line)
{

}

/* función principal que será llamada para obtener la siguiente línea del archivo. 
Se encargará de coordinar el flujo del programa, gestionar el stash y llamar a las otras funciones según sea necesario.*/

char *get_next_line(int fd)
{
	static char	*stash; // para almacenar los datos leídos, los que no fueron procesados en la primera llamada
	char		*line; // para almacenar la línea que se devolverá

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = ft_read_line(fd, *stash); // Lee una línea del descriptor de archivo y utiliza el contenido almacenado en stash. El resultado se almacena en el puntero line
	if (!line)
		return (NULL); // Si devuelve NULL indica que hubo un error al leer la línea o llegó al final del archivo
	stash = ft_set_line(line); // Toma la línea leída y actualiza stash con ella. stash podría estar almacenando el contenido restante que no se ha procesado todavía o acumulando más datos para las siguientes lecturas.
	if (!stash)
		return (NULL);
	return (line); // Si todo ha ido bien, devuelve la línea leída
}



/* 
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
		
*/