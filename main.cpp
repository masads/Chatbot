#include<iostream>
#include <fstream>
#include <stdio.h>
#include <string> 
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <cctype>
#include <windows.h>

using namespace std;

//A Simple Node
char email[100];
char name[20];
string botName = "Admin";


class node
{
	public:
		char data[200];
		node *next;
		node()
		{
			
			next=NULL;
		}
		node(char ndata[] , node *a)
		{
			strcpy(data,ndata);
			next=a;
		}
};
class linkedlist
{

		node *head ;
	public:	
		linkedlist()
		{
			head=NULL;
		}

        //Inserting Root Node
		void add_node_head(char n[])
		{
			if (head==NULL)
			{
				head=new node(n,NULL);
			}
			else 
			{
				head=new node(n,head);
			}
		}

        //Inserting A Node at End
        void insert(char n[])
        {
            
            if (head==NULL)
			{
				head=new node(n,NULL);
			}else
            {   node* p ;
                for (p=head; p->next!=NULL; p=p->next)
                {
                    
                }
                node *a=new node(n,NULL);
                p->next=a;
            }
        }
        bool delete_last_node()
        {
            if(head==NULL)
			{
				return false;
			}else if(head->next==NULL)
            {
                delete head;
                head=NULL;
            }   
            else
            {   node* p ,*pre;
                for (p=head; p->next->next!=NULL; p=p->next)
                {
                    
                }
                pre=p;
                pre=pre->next;
                delete pre;
                p->next=NULL;
            }
        }


        void print_at_given_index(int index,char *message)
        {
            node *p=head;
            int i=1;
            for (; p!=NULL ; p=p->next,i++)
            {
                if(i==index)
                {
                    strcpy(message,p->data);
                    break;
                }
            }
        }
        void delet_at_given_index(int index)
        {
            node *p=head;
            node *pre;
            if(index==1)
            {
                pre=p;
                p=p->next;
                delete pre;
                head=p;
            }else if(index==Count())
            {
                delete_last_node();
            }
            else
            {
                int i=1;
                for (; p!=NULL ; p=p->next,i++)
                {
                    if(i==index)
                    {
                        node *temp=p;
                        p=p->next;
                        delete temp;
                        pre->next=p;
                        break;
                    }
                    pre=p;
                }
            }
            
        }
		void display()
		{
            int c=1;
			node *temp=head;
			while(temp!=NULL)
			{
				cout<<c<<" "<<temp->data<<endl;
				temp=temp->next;
                c++;
			}
    
		}
        int Count()
        {
            int count=0; 
            int b=0;
            for(node *tmp=head;tmp!=NULL;tmp=tmp->next)
            {
                if(strcmp(tmp->data,"|")==0)
                {
                    b++;
                }else
                {
                    count++;
                }

            }
            count=count-b;
            return count; 
        }

        //Mainly for Useless Linked List
        void delete_words(char message[],char *message2)
        {
            node *words;
            char message3[200];
            strcpy(message3,message);
            char *inputChar=message3;
            char *value;
            value = strtok(inputChar," ");
            int flag=0;
            int z=0,x=strlen(message2);
            while(value != NULL){
                words=head;
                while(words!=NULL)
                {
                    if(stricmp(value,words->data)==0)
                    {
                        flag=1;
                        break;
                    }
                    words=words->next;
                }
                if(flag==0)
                {
                    for(int k = 0; k <strlen(value); k++)
                    {
                        if(value[k]=='?')
                        {
                            k++;
                        }
                        message2[z]=value[k];
                        z++;
                    }

                    message2[z]=' ';
                    z++;                   
                }
                flag=0;
                value = strtok(NULL," ");
            }
            message2[z]='\0';
        }
        void copy_linkedlist(linkedlist obj) {
            node *first=obj.get_head();
            while(first!=NULL)
            {
                insert(first->data);
                first=first->next;
            }
        }

        //String to Linked List
        void sentence_into_words(char message[])
        {
            char message2[200];
            strcpy(message2,message);
            char word[100]{'\0'};
            int j=0;
            for (int i = 0; i < strlen(message2); i++)
            {
                if(message2[i]==' ')
                {
                    insert(word);
                    memset(word, '\0', 100);
                    j=0;
                }else if(message2[i]=='|')
                {
                    insert(word);
                    memset(word, '\0', 100);
                    word[0]='|';
                    insert(word);
                    j=0;
                    memset(word, '\0', 100);
                }else
                {
                    word[j]=message2[i];
                    j++;
                }
            }
            if(strlen(word)!=0)
            {
                insert(word);
            }
        }

        //Linked List to String
        //First Node will be the only sentence combined
        void words_into_sentence()
        {
            node *p=get_head();
            char answer[200];
            int count=0;
            
            while(p!=NULL)
            {
                for(int i = 0; i < strlen(p->data); i++)
                {
                    answer[count]=p->data[i];
                    count++;
                }
                answer[count]=' ';
                count++;
                p=p->next;
            }
            answer[count-1]='\0';
            delete_linkedlist();
            insert(answer);
        }

        //Search for Matching Keywords - Will return the Matching keyword Count
        int search_for_linkedlist(linkedlist obj)
        {
            linkedlist temp;
            temp.copy_linkedlist(obj);
            node *first=get_head();
            node *second=temp.get_head();
            int i=1;
            int c=0;
            if(Count()==0)
            {
                return 0;
            }
            while(first!=NULL)
            {
                second=temp.get_head();
                while(second!=NULL)
                {
                    if(stricmp(first->data,second->data)==0)
                    {
                        c++;
                        if(stricmp(second->next->data,"|")==0)
                        {
                            temp.delet_at_given_index(i);
                            temp.delet_at_given_index(i);
                            temp.delet_at_given_index(i);
                        }else
                        {
                            temp.delet_at_given_index(i);
                        }
                        
                        break;
                    }else if(stricmp(second->next->data,"|")==0)
                    {
                        second=second->next->next;
                        if(stricmp(first->data,second->data)==0)
                        {
                            c++;
                            temp.delet_at_given_index(i);
                            temp.delet_at_given_index(i);
                            temp.delet_at_given_index(i);
                            break;
                        }
                    }
                    second=second->next;
                    i++;
                }
                i=1;
                first=first->next;

            }
            return c;
        }

        //Print all the words of Linked List || Only choose one word (if / is present)
        void print_word_without_or_words(linkedlist &obj)
        {
            node *first=get_head();
            node *second=obj.get_head();
            node *pre;
            int flag=0;
            if(Count()==0)
            {
                return ;
            }
           
            while(first!=NULL)
            {
                second=obj.get_head();
                while(second!=NULL)
                {
                    if(stricmp(first->data,second->data)==0)
                    {
                      
                            if(stricmp(first->next->data,"|")==0)
                            {
                                cout<<first->data<<" ";
                                first=first->next->next;
                                flag=1;
                                break;
                            } 
                        
                             
                    }
                    if(stricmp(first->next->data,"|")==0 && second->next==NULL)
                    {
                      
                        first=first->next->next;
                        break;
                        
                    }
                    second=second->next;
                }
                if(flag==0)
                {
        
                    cout<<first->data<<" ";
                 
                    
                }
                pre=first;
                first=first->next;
                flag=0;
            }
          
            cout<<endl;
        }
        
        // Delete the whole Linked List
        void delete_linkedlist()
        {
            node *ptr; 
            while(head!=NULL)
			{ 
                ptr=head->next; 
                delete head; 
                head=ptr; 
            } 

        }
        ~linkedlist()
        {
        	node *ptr; 
            while(head!=NULL)
			{ 
                ptr=head->next; 
                delete head; 
                head=ptr; 
            } 
		}	

        //Return the Head of the Linked List
        node* get_head()
        {
            return head;
        }
};

class universty 
{
    char questions[200];
    char answers[200];
    void get_useless_word(linkedlist *useless_words)
    {
        ifstream file; 
        char word[200]; 
        file.open("Useless_words.txt",ios::in);
        while(file >> word) 
        { 
            useless_words->insert(word);
            
        } 
        file.close();
    }
    public:
    void admin_menu()
    {
        char ch;
        start:

        cout <<endl;
        cout <<" ---------- ADMIN PANEL --------- "<<endl;
        cout <<"|   1.Show Pending Questions     |"<<endl;
        cout <<"|   2.Set questions and answers  |"<<endl;
        cout <<"|   3.Exit                       |"<<endl;
        cout <<" -------------------------------- "<<endl;
        cout <<"         Your Choice:";
        cin>>ch;
        cout << endl;
        if(ch=='1')
        {
            cout << "\n============= All the Pending Quesions =============\n";
            reply_unanswer_question();
            goto start;
        
        }else if(ch=='2')
        {
            set_universty_answer();
            goto start;
        }
        else if(ch=='3')
        {
            return;
        }else 
        {
            goto start;
        }
    }
    int show_unanswer_questions()
    {
        ifstream file;
        file.open("unanswer_question.txt",ios::in | ios::binary);
        if(!file)
        {
            return 0;
        }else
        {
            file.read((char*)this, sizeof(*this));
            int i=1;
            while(!file.eof()){
                cout<<i<<" "<<questions<<"  ("<<answers<<")"<<endl;
                i++;
                file.read((char*)this, sizeof(*this));
            }
            file.close();
            return i;
        }

    }

    // Admin Menu - For Pending Questions
    void reply_unanswer_question()
    {
        char ch;
       
        start:
        int numberOfUnanswerQuestion=show_unanswer_questions();
        cout<<endl;
        numberOfUnanswerQuestion++;
        cout <<" --------------------- ADMIN PANEL ------------------ "<<endl;
        cout <<"|     1. Set an Answer (For Unanswered Questions)     |"<<endl;
        cout <<"|     2. Delete a Question                            |"<<endl;
        cout <<"|     3. Go Back                                      |"<<endl;
        cout <<" ---------------------------------------------------- "<<endl;
        cout <<"                    Your Choice:";
        cin>>ch;
        if(ch=='1')
        {
            cout<<"\n\nWhich question you want to reply?\nEnter number:";
            int choose;
            cin>>choose;
            if(choose<numberOfUnanswerQuestion && 0<choose)
            {
                ifstream file;
                file.open("unanswer_question.txt",ios::in | ios::binary);
                
                if(!file)
                {
                    // cout<<"File does not exisit\n";
                    return ;
                }else
                {
                    int j=1;
                    file.read((char*)this, sizeof(*this));
                    while(!file.eof()){
                        
                        if(j==choose)
                        {
                            break;
                        }
                        j++;
                        file.read((char*)this, sizeof(*this));
                    }
                    file.close();

                    cout<<"What will be the answer?\n";
                    cin.sync();
                    cin.getline(answers,200);
                    save_in_file();
                    char msg[200];
                    strcpy(msg,questions);
                    delete_unanswer_qustion(msg);
                }
                
            }else
            {
                cout<<"Wrong Choice!\n";
                goto start;
            }
        }else if(ch=='2')
        {
            cout<<"\n\nWhich question you want to delete?\nEnter number:";
            int choose;
            cin>>choose;
            if(choose<numberOfUnanswerQuestion && 0<choose)
            {
                ifstream file;
                file.open("unanswer_question.txt",ios::in | ios::binary);
                
                if(!file)
                {
                    return ;
                }else
                {
                    int j=1;
                    file.read((char*)this, sizeof(*this));
                    while(!file.eof()){
                        
                        if(j==choose)
                        {
                            break;
                        }
                        j++;
                        file.read((char*)this, sizeof(*this));
                    }
                    file.close();
                    char msg[100];
                    strcpy(msg,questions);
                    delete_unanswer_qustion(msg);
                }
                
            }else
            {
                cout<<"wrong choice!\n";
                goto start;
            }
        }else if(ch=='3')
        {
            return ;
        }
        else
        {
            goto start;
        }
        
    }
    void delete_unanswer_qustion(char *msg)
    {
        ifstream file;
        ofstream temp;
        file.open("unanswer_question.txt",ios::in |ios::binary);
        temp.open("temp.txt",ios::out |ios::binary);
        file.read((char*)this, sizeof(*this));
        while(!file.eof()){

            if(stricmp(msg,questions)!=0)
            {
                temp.write((char*)this, sizeof(*this));
            }
            file.read((char*)this, sizeof(*this));
        }

        temp.close();
        file.close();
        remove("unanswer_question.txt");
        rename("temp.txt","unanswer_question.txt");
    }
    void set_unanswer_questions(char *msg)
    {
        if(strlen(msg)>5)
        {

            strcpy(questions,msg);
            strcpy(answers,email);
            ofstream file;
            file.open("unanswer_question.txt",ios::app |ios::binary);
            file.write((char*)this, sizeof(*this));
            file.close();
        }
    }
    void set_universty_answer()
    {
        
        cout<<"What is the question?\n";
        cin.sync();
        cin.getline(questions,200);
        cout<<"What will be the answer?\n";
        cin.sync();
        cin.getline(answers,200);
        save_in_file();
    }
    void save_in_file()
    {
        ofstream file;
        file.open("universty.txt",ios::app |ios::binary);
        file.write((char*)this, sizeof(*this));
        file.close();
    }

    //For automatic insertion
    void autoinsert()
    {
        int ch = 1;
        while(ch != 0){
            cout<<"ques: \n";
            cin.sync();
            cin.getline(questions,200);
            cout<<"ans: \n";
            cin.sync();
            cin.getline(answers,200);
            save_in_file();
            cout << "choice: ";
            cin >> ch;
        }
        
    }


    int search_for_universty_answer(char user_message[])
    {
        //Users Query is saved in User Keyword Linked List
        linkedlist user_keywords; 

        //All words of string except useless words
        linkedlist save_keywords[50];

       //All the answers in our file related to users query
        //Head-> Atif -> Atif -> Ahmed -> end
        linkedlist answer;  

        //All the questions in our file related to users query
        //Head-> who is hod -> who is hod of cs -> who is hod of ee -> end
        linkedlist question;

        //Will contain all the useless words
        linkedlist useless_words;

        //Load the useless words in Linked List
        get_useless_word(&useless_words);

        int length_of_user_question=strlen(user_message); //Length of Users Query
        int count_save_keywords=0; //Count of questions having matched keyword with users query
        int max_count=0,flag=0; 
        char user_question_keywords[length_of_user_question+1]; //Words 
        string str;
        ifstream file;
        int new_count_of_matching_words=0;
        useless_words.delete_words(user_message,user_question_keywords); //Will load all the words of users query in user_question_keywords Array except Useless Words
        user_keywords.sentence_into_words(user_question_keywords); //will load all words from user_question_keywords Array to user_keywords LinkedList
        file.open("universty.txt",ios::in | ios::binary);
        file.seekg (0, ios::beg);

        //If file does not Exist
        if(!file)
        {
            return 0;
        }
        else
        {
            file.read((char*)this, sizeof(*this));
            while(!file.eof()){

                //Length of individual question fetched from file
                int length_of_file_question=strlen(questions);

                //Will load all the words of individual question in file_keyword Array except Useless Words
                char file_keyword[length_of_file_question+1];

                //will load all words from questions array to file_keyword except useless words
                //questions -> individual question read from file 
                //question  -> Linked List of all questions

                useless_words.delete_words(questions,file_keyword);
                question.insert(questions);
                save_keywords[count_save_keywords].sentence_into_words(file_keyword);

                //count of Matching keywords between users query and question from file
                new_count_of_matching_words=user_keywords.search_for_linkedlist(save_keywords[count_save_keywords]);
                

                if(new_count_of_matching_words>0)//if found at least one keyword matched
                {

                    //Exact Match
                    if(new_count_of_matching_words==save_keywords[count_save_keywords].Count() && new_count_of_matching_words==user_keywords.Count())//if found perfect match
                    {
                        file.close();
                        answer.delete_linkedlist();
                        answer.sentence_into_words(answers);
                        cout << botName << ": ";
                        answer.print_word_without_or_words(user_keywords);
                        user_keywords.delete_linkedlist();
                        answer.delete_linkedlist();
                        question.delete_linkedlist();
                        useless_words.delete_linkedlist();
                        for (int i = 0; i < 50; i++)
                        {
                            save_keywords[i].delete_linkedlist();
                        }
                        return 1;
                    }
                    
                    else if(max_count<new_count_of_matching_words)// if found more than words than last e.g before we found one word and then found question (which is save in file) which have more then one it will delete less                            
                    {
                        max_count=new_count_of_matching_words;
                        answer.delete_linkedlist();
                        question.delete_linkedlist();
                        for (int i = 0; i < 50; i++)
                        {
                            save_keywords[i].delete_linkedlist();
                        }
                        count_save_keywords=0;
                        int length_of_file_question=strlen(questions);
                        char file_keyword[length_of_file_question+1];
                        useless_words.delete_words(questions,file_keyword);
                        question.insert(questions);
                        save_keywords[count_save_keywords].sentence_into_words(file_keyword);
                        answer.insert(answers);
                        count_save_keywords++;
                    }
                    else if(max_count>new_count_of_matching_words)
                    {
                        save_keywords[count_save_keywords].delete_linkedlist();
                        question.delete_last_node();
                    }   
                    else//save it answer for later use
                    {                                  
                        count_save_keywords++;
                        answer.insert(answers);
                    }
                }else
                {
                    save_keywords[count_save_keywords].delete_linkedlist();
                    question.delete_last_node();
                }
                 file.read((char*)this, sizeof(*this));
            }
        }
        file.close();

        
        if(save_keywords[0].Count()==0)
        {
            return 0;
        }
        //Do you mean - Functionality
        else 
        {
           
            int ch;
            int temp_count;
            temp_count = question.Count();
            linkedlist temp;
            cout << "\n" << botName << ": "<< endl;
            cout<<"Do you mean ?\n";
            for (int i = 1; i <=question.Count(); i++)
            {
                cout<<i<<". ";
                char user_answer[100];
                question.print_at_given_index(i,user_answer);
                temp.sentence_into_words(user_answer);
                temp.print_word_without_or_words(user_keywords);
                temp.delete_linkedlist();
            }
            cout << "0. If your Question is not listed above\n";
            
            redo:
            cout << "\n" << botName << ": Enter your choice\n";
            cout << name << ": "; 
            cin>>ch;
            // question.delete_linkedlist();
            // useless_words.delete_linkedlist();
            for (int i = 0; i < 50; i++)
            {
                save_keywords[i].delete_linkedlist();
            }

            
            if(ch == 0){
               
                answer.delete_linkedlist();
                user_keywords.delete_linkedlist();
                temp.delete_linkedlist();
                question.delete_linkedlist();
                useless_words.delete_linkedlist();
                return 0;
            }

            else if(ch > 0 && ch <= temp_count){

                char user_answer[200]; 
                answer.print_at_given_index(ch,user_answer);
                answer.delete_linkedlist();
                answer.sentence_into_words(user_answer);
                cout << "\n" << botName << ": ";
                
                answer.print_word_without_or_words(user_keywords);
                user_keywords.delete_linkedlist();
                answer.delete_linkedlist();
                temp.delete_linkedlist();
                question.delete_linkedlist();
                useless_words.delete_linkedlist();
                return 1;
            }

            else{
                cout << "\nInvalid Choice - Reenter Again\n";
                goto redo;
            }
        
        }
        return 0;
    }
    int get_universty_answer(char message[])
    {
        int flag=search_for_universty_answer(message);
        return flag;
    }
};
class admin
{
    char button[5];
    public:

    admin(){
        strcpy(button,"OFF");
    }
    //This function gives admin the permission to enter the admin mode
    //Some Changes Needed

    void change_button_status()
    {
        ofstream temp;
        
        char pass[10];
        cout << "Enter Password: ";
        cin.getline(pass,10);
        
        // int ch;
        // cout<<"1.ON"<<endl;
        // cout<<"2.OFF"<<endl;
        // cin>>ch;

        if(strcmp(pass,"admin123")==0)
        {
            strcpy(button,"ON");
            
        }
        else
        {
            strcpy(button,"OFF");
           
        }
        
        temp.open("temp.txt",ios::out |ios::binary);
        temp.write((char*)this, sizeof(*this));
        temp.close();
        remove("admin.txt");
        rename("temp.txt","admin.txt");
    }

    // Changes the Admin Mode to User Mode
    void auto_change()
    {
        ofstream temp;
        char *ch=get_status();
        if(strcmp(ch,"ON")==0) 
        {
            strcpy(button,"OFF");
           
            temp.open("temp.txt",ios::out |ios::binary);
            temp.write((char*)this, sizeof(*this));
            temp.close();
            remove("admin.txt");
            rename("temp.txt","admin.txt");
        }
    }

    // Gets the Value of the Admin Button Status (ON or OFF)
    char* get_status()
    {
        ifstream file;
        int status;
        file.open("admin.txt",ios::in |ios::binary);
        file.read((char*)this, sizeof(*this));
        file.close();
        return button;

    }
};

class chatbot:  public admin ,public universty
{
    char message[100];
    public:
    void user_reply(char message[])
    {
        int flag=0;
        

        admin obj;
        if(string(message)=="admin")
        {
          
            change_button_status();
           
            
        }
      
        char *temp=get_status();
        
        if(strcmp(temp,"ON")==0) 
        {
            admin_menu();
            auto_change();
        }
        else 
        {
            if(flag==0)
            {
                flag=get_universty_answer(message);//search if he ask about any universty question 
        
            }
            if(flag==0 && (string(message)!="admin"))
            {
                
                set_unanswer_questions(message);
                answer_not_found();
                
            }
        }
        
    }
    void answer_not_found()
    {
       
        cout << "\n" << botName << ": Sorry, We were unable to find an answer for your query!\n";
        cout<<"We will answer your query shortly\n";
     
        
    }
};


//Helper Functions
void gotoxy(short x, short y)                                         
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void printInfoBox(){
    int x,y;
    x = 0;
    y = 0;

    system("CLS");
    cout << " ====================== FAST BOT ======================="  << endl;
    cout << "|       Enter your Name  :                              |" << endl;
    cout << "|       Enter your Email :                              |" << endl;
    cout << " ======================================================="  << endl;

    gotoxy(x+30, y+1);
    cin.getline(name,20);

    for(int i=0; i<20; i++){
        name[i] = toupper(name[i]);
    }
    
    gotoxy(x+30, y+2);
    cin.getline(email,100);

}

//Helper Functions - END

int main()
{
    chatbot obj;

    // obj.autoinsert();

    char message[200];

    printInfoBox();

    cout << "\n" << botName << ": Hello, thank you for contacting FAST University. How can I help?\n";

    while(1)
    {
        cout << "\n" << name << ": ";
        
        cin.sync();
        cin.getline(message,200);  //Getting the User Input

        if(string(message)=="bye" || string(message)=="ok bye" || string(message)=="good bye" || string(message)=="thanks")
        {
            cout << "\n" << botName << ": See you later!"<<endl;
            break;
        }
        else
        {
            //Sending the User Reply for Searching
            obj.user_reply(message);
        }
    }
}



