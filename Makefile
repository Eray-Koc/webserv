NAME = webserv

SRCS = main.cpp WebServer.cpp Utils.cpp Response.cpp

CC = c++
RM = rm -rf

TESTERFILE = tester 

CFLAGS = -std=c++98 # -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
		$(CC) $(CFLAGS) -I./inc -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
		$(CC) ./tester.cpp -o tester

all: $(NAME)
clean: 
	$(RM) $(OBJS)
fclean: clean
		$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re