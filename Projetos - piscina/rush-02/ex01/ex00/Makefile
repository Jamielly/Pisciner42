# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcavalca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 22:20:04 by dcavalca          #+#    #+#              #
#    Updated: 2025/06/15 22:26:02 by dcavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
MAIN_DICTIONARY = numbers.dict

$(NAME):
	@cc -Wall -Wextra -Werror rush02.c -o $(NAME)

clean:
	@find . -name $(NAME) -delete

fclean: clean
	@find data -name *.dict -not -name $(MAIN_DICTIONARY) -delete
