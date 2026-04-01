#pragma once
#include <vector>
#include <mutex>
extern std::vector<int> clients;
extern std::mutex clients_mutex;
void handle_client(int client_fd);
void broadcast_msg(int sender_fd, const char* msg);
void remove_client(int client_fd);