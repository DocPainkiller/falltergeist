#include "../Engine/Mouse.h"
#include "../Engine/ResourceManager.h"
#include <iostream>
#include <cmath>

namespace Falltergeist
{

Mouse::Mouse() : InteractiveSurface()
{
    //loadFromSurface(ResourceManager::surface("art/intrface/actarrow.frm"));
    loadFromSurface(ResourceManager::surface("art/intrface/stdarrow.frm"));
    // Hide cursor
    SDL_ShowCursor(0);
    _cursorX = 320;
    _cursorY = 240;
}

Surface * Mouse::think()
{
    SDL_GetMouseState(&_cursorX, &_cursorY);
    return this;
}

Mouse::~Mouse()
{
    // Show cursor
    SDL_ShowCursor(1);
}

int Mouse::cursorX()
{
    return _cursorX;
}

int Mouse::cursorY()
{
    return _cursorY;
}

void Mouse::setCursorX(int x)
{
    _cursorX = x;
}

void Mouse::setCursorY(int y)
{
    _cursorY = y;
}

int Mouse::x()
{
    return _x + _cursorX;
}

int Mouse::y()
{
    return _y + _cursorY;
}

void Mouse::setCursor(unsigned int type)
{
    switch(type)
    {
        case BIG_ARROW:
            loadFromSurface(ResourceManager::surface("art/intrface/stdarrow.frm"));
            _x = 0; _y = 0;
            break;
        case SCROLL_W:
            loadFromSurface(ResourceManager::surface("art/intrface/scrwest.frm"));
            _x = 0; _y = - ceil(height()/2);
            break;
        case SCROLL_W_X:
            loadFromSurface(ResourceManager::surface("art/intrface/scrwx.frm"));
            _x = 0; _y = - ceil(height()/2);
            break;
        case SCROLL_N:
            loadFromSurface(ResourceManager::surface("art/intrface/scrnorth.frm"));
            _x = - ceil(width()/2); _y = 0;
            break;
        case SCROLL_N_X:
            loadFromSurface(ResourceManager::surface("art/intrface/scrnx.frm"));
            _x = - ceil(width()/2); _y = 0;
            break;
        case SCROLL_S:
            loadFromSurface(ResourceManager::surface("art/intrface/scrsouth.frm"));
            _x = - ceil(width()/2);  _y = - height();
            break;
        case SCROLL_S_X:
            loadFromSurface(ResourceManager::surface("art/intrface/scrsx.frm"));
            _x = - ceil(width()/2); _y = - height();
            break;
        case SCROLL_E:
            loadFromSurface(ResourceManager::surface("art/intrface/screast.frm"));
            _x = - width(); _y = - ceil(height()/2);
            break;
        case SCROLL_E_X:
            loadFromSurface(ResourceManager::surface("art/intrface/screx.frm"));
            _x = - width(); _y = - ceil(height()/2);
            break;
        case SCROLL_NW:
            loadFromSurface(ResourceManager::surface("art/intrface/scrnwest.frm"));
            _x = 0; _y = 0;
            break;
        case SCROLL_NW_X:
            loadFromSurface(ResourceManager::surface("art/intrface/scrnwx.frm"));
            _x = 0; _y = 0;
            break;
        case SCROLL_SW:
            loadFromSurface(ResourceManager::surface("art/intrface/scrswest.frm"));
            _x = 0; _y = - height();
            break;
        case SCROLL_SW_X:
            loadFromSurface(ResourceManager::surface("art/intrface/scrswx.frm"));
            _x = 0; _y = - height();
            break;

        case SCROLL_NE:
            loadFromSurface(ResourceManager::surface("art/intrface/scrneast.frm"));
            _x =  - width(); _y = 0;
            break;
        case SCROLL_NE_X:
            loadFromSurface(ResourceManager::surface("art/intrface/scrnex.frm"));
            _x =  - width(); _y = 0;
            break;
        case SCROLL_SE:
            loadFromSurface(ResourceManager::surface("art/intrface/scrseast.frm"));
            _x =  - width(); _y = - height();
            break;
        case SCROLL_SE_X:
            loadFromSurface(ResourceManager::surface("art/intrface/scrsex.frm"));
            _x =  - width(); _y = - height();
            break;


    }
}

}