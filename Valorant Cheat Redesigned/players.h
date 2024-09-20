#pragma once
#include <math.h>
class Players
{
public:
    float x;
    float y;
    float z;

    Players(float _x, float _y, float _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    Players()
    {
    }

    float length()
    {
        return (float)sqrt(x * x + y * y + z * z);
    }

    float dotproduct(Players dot)
    {
        return (x * dot.x + y * dot.y + z * dot.z);
    }
   public void ReadInformation(int Player)
{
    DWORD BaseAddress;

    if (Player == -1) // If Player is -1, read local player information
    {
        BaseAddress = fProcess.__dwordClient + Player_Base;
    }else
    {
        BaseAddress = fProcess.__dwordClient + EntityPlayer_Base + (Player * EntityLoopDistance);
    }
    ReadProcessMemory(fProcess.__HandleProcess, (BYTE*)BaseAddress, &CBaseEntity, sizeof(DWORD), 0);
    ReadProcessMemory(fProcess.__HandleProcess, (BYTE*)(CBaseEntity + dw_mTeamOffset), &Team, sizeof(Team), 0);
    ReadProcessMemory(fProcess.__HandleProcess, (BYTE*)(CBaseEntity + dw_Health), &Health, sizeof(Health), 0);
    ReadProcessMemory(fProcess.__HandleProcess, (BYTE*)(CBaseEntity + dw_Pos), &Position, sizeof(float[3]), 0);

    // Optionally read the number of players, only relevant for the local player
    if (Player == -1) {
        ReadProcessMemory(fProcess.__HandleProcess, (BYTE*)(fProcess.__dwordEngine + dw_PlayerCountOffs), &NumOfPlayers, sizeof(int), 0);
    }
}
};

struct Colors
{
public:
    short R;
    short G;
    short B;

    Colors()
    {

    }
    Colors(short r, short g, short b)
    {
        R = r;
        G = g;
        B = b;
    }

};

class PlayerDataVec
{
public:
    float xMouse;
    float yMouse;
    int isValid;
    float xPos;
    float yPos;
    float zPos;
    int isAlive;
    int clientNum;
    Colors color;
    char name[16];
    int pose;
    int team;
    bool visible;
    int isInGame;
    int health;

    Players VecCoords()
    {
        Players vec(xPos, zPos, yPos);
        return vec;
    }
};
