#ifndef MINI_INSTAGRAM_H
#define MINI_INSTAGRAM_H

#include <iostream>
#include <string>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

/*----------------------------- class message ---------------------------*/
class Message
{
private:
    string content;
    string sender;
    Message* next;
    Message* replies;

public:
    Message(string content, string sender);
    string getContent() const;
    string getSender() const;
    void addReply(Message* reply);
    Message* getReplies() const;
    Message* getNext() const;
    void setNext(Message* nextMessage);
};

/*--------------------------- Messgae Stack -----------------------*/
class stack
{
private:
    Message* top;
    int capacity;
    int size;

public:
    stack(int capacity);
    bool isFull();
    bool isEmpty();
    void push(const string& message, const string& sender);
    void printMessages();
    void replyToMessage(Message* message, const string& replyContent, const string& sender);
    Message* getTop() const;
};

/*--------------------- Post --------------------*/
class Post
{
private:
    string content;
    string timestamp;
    Post* next;

public:
    Post(string content);
    string getCurrentTime();
    string getContent() const;
    string getTimestamp() const;
    Post* getNext() const;
    void setNext(Post* nextPost);
};

/*----------------------------- Friend Reqest ------------------------------*/
class FriendRequest
{
private:
    string sender;
    string receiver;
    string status;
    FriendRequest* next;

public:
    FriendRequest(string s, string r, string st);
    string getSender() const;
    string getReceiver() const;
    string getStatus() const;
    FriendRequest* getNext() const;
    void setNext(FriendRequest* nextRequest);
    void setStatus(const string& newStatus);
};

/*----------------------------------------- User Class -------------------------------*/
class User
{
private:
    string name;
    string password;
    string city;
    string securityQuestion;
    string securityAnswer;
    Post* posts;
    FriendRequest* notifications;
    User* followers;
    User* following;
    User* next;
    stack* messages;
    time_t lastLogin;
    bool activeStatus;

public:
User(){}
    User(string n, string p, string c, string secQ, string secA, int stackCapacity = 100);
    ~User();
    string getName() const;
    string getPassword() const;
    Post* getPosts() const;
    User* getFollowers() const;
    User* getFollowing() const;
    FriendRequest* getNotifications() const;
    stack* getMessages() const;
    User* getNext() const;
    void setNext(User* nextUser);
    void setActiveStatus(bool status);
    bool getActiveStatus() const;
    void addPost(string content);
    void addFollower(User* follower);
    void addFollowing(User* follow);
    void addNotification(FriendRequest* request);
    void addMessage(const string& message);
    void updateLastLogin();
    string getLastLoginTime() const;
};

/* --------------------------------------- BST CLASS -----------------------------------*/
class UserBST
{
private:
    struct Node
    {
        User* user;
        Node* left;
        Node* right;
        Node(User* user);
    };
    Node* root;
    Node* insertRecursive(Node* node, User* user);
    User* findRecursive(Node* node, const string& username);

public:
    UserBST();
    void insert(User* user);
    User* findUser(const string& username);
};

/*---------------------------- friends request queue ------------------------------*/
class FRqueue
{
private:
    FriendRequest* front;
    FriendRequest* rear;

public:
    FRqueue();
    void enqueue(FriendRequest* req);
    FriendRequest* dequeue();
    bool isEmpty();
};

/*--------------------------------- class to mange all realtion/ netwroks of user ------------------------*/
class user_networks
{
private:
    UserBST users;
    FRqueue requests;
    User* currentUser;

public:
    user_networks();
    void signup(string name, string password, string city, string secQ, string secA);
    User* login(string name, string password);
    void logout();
    void sendFriendRequest(string receiver);
    void acceptFriendRequest();
    void sendMessage();
    void viewMessages();
    void createPost();
    void viewPosts();
    void newsFeed();
    void showFollowers();
    void showFollowing();
    void showNotifications();
    void showMenu();
};

#endif // MINI_INSTAGRAM_H