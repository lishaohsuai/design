#include<iostream>
using namespace std;
//状态模式
class War;
class State
{
    public:
        virtual void Prophase(){}
        virtual void Metaphase(){}
        virtual void Anaphase(){}
        virtual void End(){}
        virtual void CurrentState(War *war){}
};
//战争
class War
{
    private:
        State *m_state;//目前状态
        int m_days;
    public:
        War(State *state):m_state(state), m_days(0){}
        ~War()
        {
           delete m_state;
        }
        int GetDays()
        {
            return m_days;
        }
        void SetDays(int days)
        {
            m_days = days;
        }
        void SetState(State *state)
        {
            delete m_state;
            m_state = state;
        }
        void GetState()
        {
            m_state->CurrentState(this);//调用对应状态的函数显示相应的行为  或许是最关键的一句话语了
        }
};
//战争结束
class EndState:public State
{
    public:
        void End(War *war) // 结束状态的具体行为
        {
            cout<<"战争结束"<<endl;
        }
        void CurrentState(War *war)
        {
            End(war);
        }
};
//后期
class AnaphaseState:public State
{
    public:
        void Anaphase(War *war)//后期的具体行为
        {
            if(war->GetDays()<30)
                cout<<"第"<<war->GetDays()<<"天:战争后期,双方拼死一搏"<<endl;
            else
            {
                war->SetState(new EndState());
                war->GetState();
            }
        }
        void CurrentState(War *war)
        {
            Anaphase(war);
        }
};
//中期
class MetaphaseState:public State
{
    public:
        void Metaphase(War *war) //中期的具体行为
        {
            if(war->GetDays()<20)
                cout<<"第"<<war->GetDays()<<"天:战争中期,进入相持阶段,双方各有损耗"<<endl;
            else
            {
                war->SetState(new AnaphaseState());
                war->GetState();
            }
        }
        void CurrentState(War *war)
        {
            Metaphase(war);
        }
};
//前期
class ProphaseState:public State
{
    public:
        void Prophase(War *war)  //前期的具体行为
        {
            if(war->GetDays() <10)
            {
                cout<<"第"<<war->GetDays()<<"天:战争除夕前双方你来我往,互相试探对方"<<endl;
            }
            else
            {
                war->SetState(new MetaphaseState());
                war->GetState();
            }
        }
        void CurrentState(War *war)
        {
            Prophase(war);
        }
};
int main()
{
    War *war = new War(new ProphaseState());//采用ProphaseState初期状态初始化一个战争
    for(int i = 1; i < 40;i++)
    {
        war->SetDays(i);
        war->GetState();
    }
    delete war;
    return 0;
}
