# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    runtetrigen.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briffard <briffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 15:50:16 by briffard          #+#    #+#              #
#    Updated: 2022/01/19 16:17:13 by briffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

printf "Option 1:\nv -> valid map\n"
printf "i -> invalid map\n"
read OPTION1
printf "Option 2:\n"
printf "f -> to write map in a file\n"
printf "s -> to send map to stdin\n"
read OPTION2
printf "Select the number of tetriminos do you want. The number should souldt be
between 1 and 26\n"
read NUM
./eval_test/tetrigene -${OPTION1} -${OPTION2} ${NUM}