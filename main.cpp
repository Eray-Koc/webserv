#include "webserv.hpp"
#include "WebServer.hpp"

WebServer *g_server = NULL;
std::vector<Server> servers;

void ServerKill(int sig) {
    (void) sig;
    delete g_server;
    for (int i = 0; i < servers.size(); i++)
    {
        delete &servers[i];
    }
    
    std::cout << "\nServer Killed!" << std::endl;
    exit(1);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try {
            servers = parse_config(av[1]);
            
            // print_servers(servers);
            if (servers.size() == 0)
            {
                std::cerr << "No server found in the configuration file." << std::endl;
                return (1);
            }
            WebServer *serv  = new WebServer(servers);
            g_server = serv;
            signal(SIGINT, ServerKill);
            signal(SIGPIPE, SIG_IGN);
            serv->start();
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            return (1);
        }
        return (0);
    }
    std::cerr << "Please try : ./webserv [configuration file]" << std::endl; 
    return (1);

}


