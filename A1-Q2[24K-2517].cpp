#include <iostream>
#include <string>
#include <tuple>

using namespace std;

class Ball
{
private:
    int x, y;

public:
    Ball(int startX, int startY) : x(startX), y(startY) {}

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }

    tuple<int, int> getPosition() const
    {
        return make_tuple(x, y);
    }
};

class Robot
{
private:
    string name;
    int hits;

public:
    Robot(const string &robotName) : name(robotName), hits(0) {}

    void hitBall(int &ballX, int &ballY, const string &direction)
    {
        if (direction == "up")
            ballY++;
        else if (direction == "down")
            ballY--;
        else if (direction == "left")
            ballX--;
        else if (direction == "right")
            ballX++;
        hits++;
    }

    int getHits() const
    {
        return hits;
    }

    string getName() const
    {
        return name;
    }
};

class Goal
{
private:
    int x, y;

public:
    Goal(int goalX, int goalY) : x(goalX), y(goalY) {}

    bool isGoalReached(int ballX, int ballY) const
    {
        return ballX == x && ballY == y;
    }
};

class Team
{
private:
    string teamName;
    Robot *robot;

public:
    Team(const string &name, Robot *robotPlayer) : teamName(name), robot(robotPlayer) {}

    string getTeamName() const
    {
        return teamName;
    }

    Robot *getRobot() const
    {
        return robot;
    }
};

class Game
{
private:
    Team *teamOne;
    Team *teamTwo;
    Ball ball;
    Goal goal;

public:
    Game(Team *t1, Team *t2, int ballStartX, int ballStartY, int goalX, int goalY)
        : teamOne(t1), teamTwo(t2), ball(ballStartX, ballStartY), goal(goalX, goalY) {}

    void startGame()
    {
        int ballX = ball.getX();
        int ballY = ball.getY();
        Team *currentTeam = teamOne;

        while (!goal.isGoalReached(ballX, ballY))
        {
            Robot *robot = currentTeam->getRobot();
            string direction;

            cout << "Enter direction (up, down, left, right) for " << currentTeam->getTeamName() << ": ";
            cin >> direction;

            robot->hitBall(ballX, ballY, direction);
            ball.move(ballX - ball.getX(), ballY - ball.getY());

            cout << "Ball is now at (" << ballX << ", " << ballY << ")\n";

            currentTeam = (currentTeam == teamOne) ? teamTwo : teamOne;
        }
    }

    void declareWinner() const
    {
        int hitsTeamOne = teamOne->getRobot()->getHits();
        int hitsTeamTwo = teamTwo->getRobot()->getHits();

        cout << teamOne->getTeamName() << " hits: " << hitsTeamOne << endl;
        cout << teamTwo->getTeamName() << " hits: " << hitsTeamTwo << endl;

        if (hitsTeamOne < hitsTeamTwo)
        {
            cout << teamOne->getTeamName() << " wins!" << endl;
        }
        else if (hitsTeamTwo < hitsTeamOne)
        {
            cout << teamTwo->getTeamName() << " wins!" << endl;
        }
        else
        {
            cout << "It's a tie" << endl;
        }
    }
};

int main()
{
    cout << "Hasan Waseem : 24K2517" << endl;
    Robot robot1("Robot1");
    Robot robot2("Robot2");

    Team team1("Hasan", &robot1);
    Team team2("Waqar", &robot2);

    Game game(&team1, &team2, 0, 0, 3, 3);

    game.startGame();
    game.declareWinner();

    return 0;
}