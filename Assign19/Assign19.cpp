#include<iostream>
using namespace std;
#include<string.h>
class Game
{
  private:
    int g_score[5];
  public:
    void setScore(int round,int score)
    {
      this->g_score[round-1]=score;
    }
    
    int getScore(int round){return this->g_score[round-1];}
};

class GameResult:public Game
{
  private:
    int result[5];
   
  public:
    static const int win = 2;
    static const int lose = 0;
    static const int draw = 1;
    void setResult(int round,int result)
    {
      this->result[round-1]=result;
    }

    int getResult(int round){return this->result[round-1]; }

    void finalresult()
    {
      int scoreSum = 0,resultSum = 0;
      for(int i=0;i<5;i++)
      {
        scoreSum = scoreSum + getScore(i+1);
        resultSum = resultSum + result[i+1];
      }
      cout<<"\nTotal score = "<<scoreSum<<endl;
      cout<<"\n Total Result = "<<resultSum<<endl;
    }
};

class Actor
{
  private:
    char name[20];
    int age;
  public:
    void setName(char name[]){strcpy(this->name,name);}
     
    void setAge(int age){this->age =age;}

    char* getName(){return this->name;}

    int getAge(){return this->age;}
};

class TVActor:virtual public Actor
{
  private:
    int projectDone;
  public:
    void setTVProjectcount(int p){projectDone = p;}
    int getTVProjectcount(){return projectDone;}
    void setTVActor(char name[],int age,int p)
    {
      setName(name);
      setAge(age);
      setTVProjectcount(p);
    }  
    void ShowTvActor()
    {
      cout<<endl;
      cout<<getName()<<" "<<getAge()<<" "<<getTVProjectcount()<<endl;
    }
    
};

class MovieActor:virtual public Actor
{
  private:
    int movieDone;
  public:
    void setMovieCount(int mDone){movieDone = mDone;}
    int getMovieCount(){return movieDone;}
    void setMovieActor(char name[],int age,int mDone)
    {
      setName(name);
      setAge(age);
      setMovieCount(mDone);
    }  
    void showMovieActor()
    {
      cout<<endl;
      cout<<getName()<<" "<<getAge()<<" "<<getMovieCount()<<endl;
    }
};

class AllScreenActor:public TVActor,MovieActor
{
  public:
    void setActorData(char name[],int age,int tvProject,int movieProject)
    {
      setName(name);
      setAge(age);
      setTVProjectcount(tvProject);
      setMovieCount(movieProject);
    }

    void showActorData()
    {
      cout<<endl;
      cout<<getName()<<" ";
      cout<<getAge()<<" ";
      cout<<getTVProjectcount()<<" ";
      cout<<getMovieCount()<<" "<<endl;
    }
};


