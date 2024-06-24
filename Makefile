### COMPILE ####################################################################
CC = cc
CFLAGS = -Werror -Wextra -Wall -I $(INC_DIR)

### LIB NAME ###################################################################
NAME = libftprintf.a

### SRC ###############################################################################
SRC  = ft_printf.c
SRC += ft_printf_nbrs.c
SRC += ft_printf_chars.c

### INC DIRECTORY #################################################################
INC_DIR =./includes/

### OBJ FILES #####################################################################
OBJS := $(SRC:.c=.o)

### COMMANDS ######################################################################
RM   = rm -f
AR   = ar rcs

################################################################################

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

run: all
	@$(CC) $(CFLAGS) main.c $(NAME)
	./a.out
	@$(RM) a.out


re: fclean all

.PHONY : all clean fclean re
