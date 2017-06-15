#include<iostream>
#include<vector>
//在逻辑上每一个出现的字符都有一个对象与之对应，然而在物理上它们却共享同一个享元对象
using namespace std;
//棋子的颜色
enum PieceColor { BLACK, WHITE};
//棋子的位置
struct PiecePos
{
    int x;
    int y;
    PiecePos(int a, int b): x(a), y(b){}
};
//棋子的定义
class Piece
{
    protected:
        PieceColor m_color;//颜色
        PiecePos m_pos;    //位置
    public:
        Piece(PieceColor color, PiecePos pos):m_color(color), m_pos(pos){}
        ~Piece(){}
        virtual void Draw(){}
};
class BlackPiece:public Piece
{
    public:
        BlackPiece(PieceColor color, PiecePos pos):Piece(color, pos){}
        ~BlackPiece(){}
        void Draw()
        {
            cout<<"绘制一颗黑棋"<<endl;
        }
};
class WhitePiece:public Piece
{
    public:
        WhitePiece(PieceColor color, PiecePos pos):Piece(color, pos){}
        ~WhitePiece(){}
        void Draw()
        {
            cout<<"绘制一颗白棋"<<endl;
        }
};

class PieceBoard
{
    private:
        vector<PiecePos>m_vecPos;//棋盘上的位置
        string m_blackName;//黑方执手
        string m_whiteName;//白方执手
        Piece *m_blackPiece;//黑方棋子
        Piece *m_whitePiece;//白方棋子
    public:
        PieceBoard(string black, string white):m_blackName(black), m_whiteName(white)
        {
            m_blackPiece = NULL;
            m_whitePiece = NULL;
        }
        ~PieceBoard(){delete m_blackPiece; delete m_whitePiece;}
        void SetPiece(PieceColor color, PiecePos pos)//一步棋在棋盘放一颗棋子
        {
            if(color == BLACK)//黑方下的
            {
                if(m_blackPiece == NULL)//只有一颗黑棋子和白棋子的实例
                    m_blackPiece = new BlackPiece(color);
                cout<<m_blackName<<"在位置("<<pos.x<<','<<pos.y<<")";
                m_blackPiece->Draw();
            }
            else
            {
               if(m_whitePiece == NULL)
                    m_whitePiece = new WhitePiece(color);
                cout<<m_whiteName<<"在位置("<<pos.x<<','<<pos.y<<")";
                m_whitePiece->Draw();
             }
            m_vecPos.push_back(pos); //加入容器中
        }
};
int main()
{
    PieceBoard pieceBoard("A","B");
    pieceBoard.SetPiece(BLACK, PiecePos(4, 4));
    pieceBoard.SetPiece(WHITE, PiecePos(4, 16));
    pieceBoard.SetPiece(BLACK, PiecePos(4, 4));
    pieceBoard.SetPiece(WHITE, PiecePos(4, 16));
}


