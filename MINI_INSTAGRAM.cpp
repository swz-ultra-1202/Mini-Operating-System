#include <iostream>
#include <string>
#include <ctime>
//#include<Windows.h>
#include<unistd.h>
#include <cstdlib>
#include <iomanip>
#include "MINI_INSTAGRAM.h"
using namespace std;

/*----------------------------- class message ---------------------------*/

Message::Message(string content, string sender) : content(content), sender(sender), next(NULL), replies(NULL) {}

    string Message::getContent() const
    {
        return content;
    }

    string Message::getSender() const
    {
        return sender;
    }

    void Message::addReply(Message* reply)
    {
        reply->next = replies;
        replies = reply;
    }

    Message* Message::getReplies() const
    {
        return replies;
    }

    Message* Message::getNext() const
    {
        return next;
    }

    void Message::setNext(Message* nextMessage)
    {
        next = nextMessage;
    }


/*--------------------------- Messgae Stack -----------------------*/

    stack::stack(int capacity) : capacity(capacity), top(NULL), size(0) {}

    bool stack::isFull()
    {
        return size == capacity;
    }

    bool stack::isEmpty()
    {
        return size == 0;
    }

    void stack::push(const string& message, const string& sender) // if there are new messages then they push into stack
    {
        if (!isFull())
        {
            Message* newMessage = new Message(message, sender);
            newMessage->setNext(top);
            top = newMessage;
            size++;
        }
        else
        {
            cout << "Message stack is full!" << endl;
        }
    }

    void stack::printMessages()
    {
        if (isEmpty())
        {
            cout << "No new messages!" << endl;
        }
        else
        {
            Message* temp = top;
            int index = 0;
            while (temp)
            {
                cout << index++ << ". Message from " << temp->getSender() << ": " << temp->getContent() << endl;
                Message* reply = temp->getReplies();
                while (reply)
                {
                    cout << "\tReply : " << reply->getContent() << " ( by " << reply->getSender() << " ) . " << endl;
                    reply = reply->getNext();
                }
                temp = temp->getNext();
            }
        }
    }

    void stack::replyToMessage(Message* message, const string& replyContent, const string& sender)
    {
        Message* reply = new Message(replyContent, sender);
        message->addReply(reply);
    }

    Message* stack::getTop() const
    {
        return top;
    }


/*--------------------- Post --------------------*/

Post::Post(string content) : content(content), next(NULL)
    {
        timestamp = getCurrentTime();
    }

    string Post::getCurrentTime()
    {
        time_t now = time(0);
        char* dt = ctime(&now);
        return string(dt);
    }

    string Post::getContent() const
    {
        return content;
    }

    string Post::getTimestamp() const
    {
        return timestamp;
    }

    Post* Post::getNext() const
    {
        return next;
    }

    void Post::setNext(Post* nextPost)
    {
        next = nextPost;
    }


/*----------------------------- Friend Reqest ------------------------------*/

FriendRequest::FriendRequest(string s, string r, string st) : sender(s), receiver(r), status(st), next(NULL) {}

    string FriendRequest::getSender() const
    {
        return sender;
    }

    string FriendRequest::getReceiver() const
    {
        return receiver;
    }

    string FriendRequest::getStatus() const
    {
        return status;
    }

    FriendRequest* FriendRequest::getNext() const
    {
        return next;
    }

    void FriendRequest::setNext(FriendRequest* nextRequest)
    {
        next = nextRequest;
    }

    void FriendRequest::setStatus(const string& newStatus)
    {
        status = newStatus;
    }


/*----------------------------------------- User Class -------------------------------*/

User::User(string n, string p, string c, string secQ, string secA, int stackCapacity ): name(n), password(p), city(c), securityQuestion(secQ), securityAnswer(secA), posts(NULL),notifications(NULL), followers(NULL), following(NULL), next(NULL), lastLogin(time(0)), activeStatus(false)
    {
        messages = new stack(stackCapacity);
    }

    User::~User()
    {
        delete messages;
    }

    string User::getName() const
    {
        return name;
    }

    string User::getPassword() const
    {
        return password;
    }

    Post* User::getPosts() const
    {
        return posts;
    }

    User* User::getFollowers() const
    {
        return followers;
    }

    User* User::getFollowing() const
    {
        return following;
    }

    FriendRequest* User::getNotifications() const
    {
        return notifications;
    }

    stack* User::getMessages() const
    {
        return messages;
    }

    User* User::getNext() const
    {
        return next;
    }

    void User::setNext(User* nextUser)
    {
        next = nextUser;
    }

    void User::setActiveStatus(bool status)
    {
        activeStatus = status;
    }

    bool User::getActiveStatus() const
    {
        return activeStatus;
    }

    void User::addPost(string content)
    {
        Post* newPost = new Post(content);
        newPost->setNext(posts);
        posts = newPost;
    }

    void User::addFollower(User* follower)
    {
        follower->setNext(followers);
        followers = follower;
    }

    void User::addFollowing(User* follow)
    {
        follow->setNext(following);
        following = follow;
    }

    void User::addNotification(FriendRequest* request)
    {
        request->setNext(notifications);
        notifications = request;
    }

    void User::addMessage(const string& message)
    {
        messages->push(message, name);
    }

    void User::updateLastLogin()
    {
        lastLogin = time(0);
    }

    string User::getLastLoginTime() const
    {
        char* dt = ctime(&lastLogin);
        return string(dt);
    }

/* --------------------------------------- BST CLASS -----------------------------------*/


    
UserBST:: Node::Node(User* user) : user(user), left(NULL), right(NULL) {}
   

   
        UserBST::UserBST() : root(NULL) {}

    void UserBST::insert(User* user)
    {
        root = insertRecursive(root, user);
    }

    User* UserBST::findUser(const std::string& username)
    {
        return findRecursive(root, username);
    }


UserBST::Node* UserBST::insertRecursive(Node* node, User* user)
    {
        if (node == NULL)
        {
            return new Node(user);
        }

        if (user->getName() < node->user->getName())
        {
            node->left = insertRecursive(node->left, user);
        }
        else
        {
            node->right = insertRecursive(node->right, user);
        }

        return node;
    }

    User* UserBST::findRecursive(Node* node, const std::string& username)
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (username == node->user->getName())
        {
            return node->user;
        }
        else if (username < node->user->getName())
        {
            return findRecursive(node->left, username);
        }
        else
        {
            return findRecursive(node->right, username);
        }
    }

/*---------------------------- friends request queue ------------------------------*/

FRqueue::FRqueue() : front(NULL), rear(NULL) {}

    void FRqueue::enqueue(FriendRequest* req)
    {
        if (rear)
        {
            rear->setNext(req);
            rear = req;
        }
        else
        {
            front = rear = req;
        }
    }

    FriendRequest* FRqueue::dequeue()
    {
        if (!front) return NULL;
        FriendRequest* temp = front;
        front = front->getNext();
        if (!front) rear = NULL;
        return temp;
    }

    bool FRqueue::isEmpty()
    {
        return front == NULL;
    }


/*--------------------------------- class to mange all realtion/ netwroks of user ------------------------*/

user_networks::user_networks() : currentUser(NULL) {}

    void user_networks::signup(string name, string password, string city, string secQ, string secA)
    {
        if (users.findUser(name))
        {
            cout << "Username already exists!" << endl;
            return;
        }
        User* newUser = new User(name, password, city, secQ, secA);
        users.insert(newUser);
        cout << "User signed up successfully!" << endl;
    }

    User* user_networks::login(string name, string password)
    {
        User* user = users.findUser(name);
        if (user && user->getPassword() == password)
        {
            currentUser = user;
            currentUser->updateLastLogin();
            currentUser->setActiveStatus(true);
            cout << "Login successful!" << endl;
            return user;
        }
        cout << "Invalid username or password!" << endl;
        return NULL;
    }

    void user_networks::logout()
    {
        if (currentUser)
        {
            currentUser->setActiveStatus(false);
            cout << "Logged out successfully!" << endl;
        }
        currentUser = NULL;
    }

    void user_networks::sendFriendRequest(string receiver)
    {
        if (!currentUser)
        {
            cout << "Please login first!" << endl;
            return;
        }
        User* receiverUser = users.findUser(receiver);
        if (!receiverUser)
        {
            cout << "Receiver user not found!" << endl;
            return;
        }
        FriendRequest* request = new FriendRequest(currentUser->getName(), receiverUser->getName(), "pending");
        requests.enqueue(request);
        receiverUser->addNotification(request);
        cout << "Friend request sent to " << receiver << "!" << endl;
    }


    void user_networks::acceptFriendRequest()
    {
        if (!currentUser)
        {
            cout << "Please login first!" << endl;
            return;
        }
        if (requests.isEmpty())
        {
            cout << "No friend requests!" << endl;
            return;
        }
        FriendRequest* req = requests.dequeue();
        req->setStatus("accepted");
        User* senderUser = users.findUser(req->getSender());
        User* receiverUser = users.findUser(req->getReceiver());
        senderUser->addFollowing(receiverUser);
        receiverUser->addFollower(senderUser);
        cout << "Friend request from " << req->getSender() << " accepted!" << endl;

        char followBack;
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << "Do you want to follow back " << req->getSender() << "? \nEnter y for yes otherwise prees any key : ";
        cin >> followBack;
        if (followBack == 'y' || followBack == 'Y')
        {
            senderUser->addFollower(receiverUser);
            receiverUser->addFollowing(senderUser);
            cout << "Followed back " << req->getSender() << "!" << endl;
        }
    }


    void user_networks::sendMessage()
    {
        if (!currentUser)
        {
            cout << "Please login first!" << endl;
            return;
        }
        string recipient, message;
        cout << "Enter name to send message : ";
        cin >> recipient;
        cout << "Enter your message : ";
        cin.ignore();
        getline(cin, message);

        User* recipientUser = users.findUser(recipient);
        if (!recipientUser)
        {
            cout << "Recipient user not found!" << endl;
            return;
        }

        recipientUser->addMessage(message);
        cout << "Message sent successfully!" << endl;
    }

    void user_networks::viewMessages()
    {
        if (!currentUser)
        {
            cout << "Please login first!" << endl;
            return;
        }
        currentUser->getMessages()->printMessages();
        cout << "-------------------------------------------------------------" << endl;
        cout << "Do you want to reply to any message? (y/n) : ";
        char replyChoice;
        cin >> replyChoice;

        if (replyChoice == 'y' || replyChoice == 'Y')
        {
            cout << "Enter the number of the message you want to reply to : ";
            int messageIndex;
            cin >> messageIndex;

            Message* message = currentUser->getMessages()->getTop();
            int index = 0;
            while (message && index < messageIndex)
            {
                message = message->getNext();
                index++;
            }

            if (message)
            {
                cout << "Enter your reply: ";
                string replyContent;
                cin.ignore();
                cin >> replyContent;

                currentUser->getMessages()->replyToMessage(message, replyContent, currentUser->getName());
                cout << "Reply sent!" << endl;
            }
            else
            {
                cout << "Invalid message index!" << endl;
            }
        }
    }
    void user_networks::createPost()
    {
        if (!currentUser)
        {
            cout << "Please login first!" << endl;
            return;
        }
        string content;
        cout << "Enter post content: ";
        cin.ignore();
        getline(cin, content);
        currentUser->addPost(content);
        cout << "Post created!" << endl;
    }

    void user_networks::viewPosts()
    {
        if (!currentUser)
        {
            cout << "Please login first!" << endl;
            return;
        }
        Post* temp = currentUser->getPosts();
        while (temp)
        {
            cout << "Post : " << temp->getContent() << "\nPosted on: " << temp->getTimestamp() << endl;
            temp = temp->getNext();
        }
    }

    void user_networks::newsFeed()
    {
        if (!currentUser)
        {
            cout << "Please login first!" << endl;
            return;
        }
        cout << "News Feed for " << currentUser->getName() << " : " << endl;
        User* temp = currentUser->getFollowing();
        while (temp)
        {
            cout << "Posts by " << temp->getName() << ":\n";
            viewPosts();
            temp = temp->getNext();
        }
    }

    void user_networks::showFollowers()
    {
        if (!currentUser)
        {
            cout << "Please login first!" << endl;
            return;
        }
        cout << "Followers of " << currentUser->getName() << ":" << endl;
        User* temp = currentUser->getFollowers();
        while (temp)
        {
            cout << temp->getName() << endl;
            temp = temp->getNext();
        }
    }

    void user_networks::showFollowing()
    {
        if (!currentUser)
        {
            cout << "Please login first!" << endl;
            return;
        }
        cout << "Following of " << currentUser->getName() << ":" << endl;
        User* temp = currentUser->getFollowing();
        while (temp)
        {
            cout << temp->getName() << endl;
            temp = temp->getNext();
        }
    }

    void user_networks::showNotifications()
    {
        if (!currentUser)
        {
            cout << "Please login first!" << endl;
            return;
        }
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "Notifications for " << currentUser->getName() << ":" << endl;
        FriendRequest* temp = currentUser->getNotifications();
        while (temp)
        {
            cout << temp->getSender() << " - Status: " << temp->getStatus() << endl;
            temp = temp->getNext();
        }
    }

    void user_networks::showMenu()
    {
      

        system("color 0b");
        cout << "\n\t\t\t+------------------------------------------------------------------------------------+\n";
        
        
        cout << "\t\t\t|                                                                                    |" << endl;
        sleep(1);
        cout << "\t\t\t|                                                                                    |" << endl;
        sleep(1);
        cout << "\t\t\t|                                                                                    |" << endl;
        sleep(1);
        cout << "\t\t\t|                                                                                    |" << endl;
        sleep(1);
        cout << "\t\t\t|                                                                                    |" << endl;
        sleep(1);
        cout << "\t\t\t|                                                                                    |" << endl;
        sleep(1);
        cout << "\t\t\t|                                                                                    |" << endl;
        sleep(1);
        cout << "\t\t\t|                        Welcome to Mini Instagram!                                  |" << endl;
        sleep(1);
        cout << "\t\t\t|                                                                                    |" << endl;
        sleep(1);
        cout << "\t\t\t|                                                                                    |" << endl;
        sleep(1);
        cout << "\t\t\t|                                                                                    |" << endl;
        sleep(1);
        cout << "\t\t\t|                                                                                    |" << endl;
        sleep(1);
        cout << "\t\t\t|                                                                                    |" << endl;
        sleep(1);
        cout << "\t\t\t|                                                                                    |" << endl;
        sleep(1);
        cout << "\t\t\t|                                                                                    |" << endl;
        sleep(1);
        cout << "\t\t\t+-------------------------------------------------------------------------------------+\n";
        sleep(1);
        cout << "\n\n\t\t\t---------------------------------------------------------------------------------------\n";
        sleep(1);
        cout << "\t\t\t Presented By : " << endl;
        sleep(1);
        cout << "\t\t\t\t\t 23F-3077 Muhammad Shah Nawaz  " << endl;
        sleep(1);
        cout << "\t\t\t\t\t 23F-6043 Abdul Mujeeb  " << endl;
        sleep(1);
        cout << "\t\t\t\t BSE-4A   " << endl;
        sleep(1);
        cout << "\t\t\t---------------------------------------------------------------------------------------\n";
        cout << endl << endl;
        sleep(5);
        //sleep(4);
        system("clear");
        int choice;
        do
        {
            system("color 0b");
            cout << "\n\t\t\t\t+----------------------- Menu : -------------------------------+ \n";
            cout << "\t\t\t\t|1. Signup                                                      | \n";
            cout << "\t\t\t\t|2. Login                                                       | \n";
            cout << "\t\t\t\t|3. Send Friend Request                                         | \n";
            /*if (!requests.isEmpty())
            {
                SetConsoleTextAttribute(h, 1);
            }*/
            cout << "\t\t\t\t|4. Accept Friend Request                                       | \n";
            cout << "\t\t\t\t|5. Create Post                                                 | \n";
            cout << "\t\t\t\t|6. View Posts                                                  | \n";
            cout << "\t\t\t\t|7. Newsfeed                                                    | \n";
            cout << "\t\t\t\t|8. Send Message                                                | \n";
            /*if (currentUser->getMessages() != NULL)
            {
                SetConsoleTextAttribute(h, 1);
            }*/
            cout << "\t\t\t\t|9. View Messages                                               | \n";

            cout << "\t\t\t\t|10. Show Notifications                                         | \n";
            cout << "\t\t\t\t|11. Show Followers                                             | \n";
            cout << "\t\t\t\t|12. Show Following                                             | \n";
            cout << "\t\t\t\t|13. Logout                                                     | \n";
            cout << "\t\t\t\t|14. search for a user                                          | \n";
            cout << "\t\t\t\t|15. Exit                                                       | \n";
            cout << "\t\t\t\t+---------------------------------------------------------------+ \n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                system("color 0c");
                system("clear");
                cout << "------------------------------------- Sing Up--------------------------" << endl;

                string name, password, city, secQ, secA;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter password: ";
                cin >> password;
                cout << "Enter city: ";
                cin >> city;
                cout << "Enter security question: ";
                cin.ignore();
                getline(cin, secQ);
                cout << "Enter security answer: ";
                getline(cin, secA);
                signup(name, password, city, secQ, secA);
                sleep(4);
                system("clear");
                break;
            }
            case 2:
            {
                system("clear");
                system("color 0A");
                cout << "------------------------------------- Log In --------------------------" << endl;
                string name, password;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter password: ";
                cin >> password;
                login(name, password);
                sleep(4);
                system("clear");
                break;
            }
            case 3:
            {
                system("clear");
                system("color 0d");
                cout << "--------------- Send request ------------------\n";
                string receiver;
                cout << "Enter receiver's username: ";
                cin >> receiver;
                sendFriendRequest(receiver);
                sleep(4);
                system("clear");
                break;
            }
            case 4:
            {
                system("clear");
                system("color 0d");
                cout << "--------------- Accept request ------------------\n";
                acceptFriendRequest();
                sleep(4);
                system("clear");
                break;
            }
            case 5:
            {
                system("clear");
                system("color 0a");
                cout << "--------------- Create Post ------------------\n";
                createPost();
                sleep(4);
                system("clear");
                break;
            }
            case 6:
            {
                system("clear");
                system("color 71");
                cout << "--------------- View Post ------------------\n";
                viewPosts();
                sleep(4);
                system("clear");
                break;
            }
            case 7:
            {
                system("clear");
                system("color 07");
                cout << "--------------- News Feed ------------------\n";
                newsFeed();
                sleep(4);
                system("clear");
                break;
            }
            case 8:
            {
                system("clear");
                system("color 0f");
                cout << "--------------- Send Message ------------------\n";
                sendMessage();
                sleep(4);
                system("clear");
                break;
            }
            case 9:
            {
                system("clear");
                system("color 12");
                cout << "--------------- View Message ------------------\n";
                viewMessages();
                sleep(4);
                system("clear");
                break;
            }
            case 10:
            {
                system("clear");
                system("color 03");
                cout << "--------------- Show Notifications ------------------\n";
                showNotifications();
                sleep(4);
                system("clear");
                break;
            }
            case 11:
            {
                system("clear");
                system("color 01");
                cout << "--------------- Followers ------------------\n";
                showFollowers();
                sleep(4);
                system("clear");
                break;
            }
            case 12:
            {
                system("clear");
                system("color 05");
                cout << "--------------- Following ------------------\n";
                showFollowing();
                sleep(4);
                system("clear");
                break;
            }
            case 13:
            {
                system("clear");
                system("color 0a");
                cout << "--------------- Log Out ------------------\n";
                logout();
                sleep(4);
                system("clear");
                break;
            }
            case 14:
            {
                system("clear");
                system("color 02");
                cout << "--------------- Search A User ------------------\n";
                string username;
                cout << "Enter username to find : ";
                cin >> username;
                User* user = users.findUser(username);
                if (user)
                {
                    cout << "User Found" << endl;
                }
                else
                {
                    cout << "Not Found" << endl;
                }
                sleep(4);
                system("clear");
                break;
            }
            case 15:
                system("clear");
                cout << "Exiting..." << endl;
                sleep(4);
                system("clear");
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
                
            }
        } while (choice != 15);
    }



