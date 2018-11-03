#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	UI.ToolsItemHeight = 50;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = DARKSLATEGREY;		//Messages color
	UI.BkGrndColor = LIGHTGRAY;	//Background color
	UI.ToolBarColor = WHITE; //Toolbar Color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = DARKGRAY;
	UI.PenWidth = 2;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
    
	CreateDrawToolBar();
	CreateStatusBar();

}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(UI.ToolBarHeight, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	Clear2ndToolBar(); //Clears the toolbar before drawing
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_Line.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\Menu_Rhom.jpg";
	MenuItemImages[ITM_ELIPSE] = "images\\MenuItems\\Menu_Elipse.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\MenuItems\\Menu_Switch.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list
	string ToolsItemImages[DRAW_ITM_COUNT];
	ToolsItemImages[ITM_COPY] = "images\\MenuItems\\Copy.jpg";
	ToolsItemImages[ITM_CUT] = "images\\MenuItems\\Cut.jpg";
	ToolsItemImages[ITM_PASTE] = "images\\MenuItems\\Paste.jpg";
	ToolsItemImages[ITM_DELETE] = "images\\MenuItems\\Delete.jpg";
	ToolsItemImages[ITM_SAVE] = "images\\MenuItems\\Save.jpg";
	ToolsItemImages[ITM_SAVETYPE] = "images\\MenuItems\\SaveType.jpg";
	ToolsItemImages[ITM_LOAD] = "images\\MenuItems\\Load.jpg";
	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	for(int i=0; i<TOOLS_ITM_COUNT; i++)
		pWind->DrawImage(ToolsItemImages[i], 0, i*UI.ToolBarHeight+UI.ToolBarHeight, UI.ToolBarHeight, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(LIGHTSLATEGREY, 1);
	pWind->DrawLine(0, 0, UI.width, 0);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
	//Draw a line above the statusbar
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight-1, UI.width, UI.height - UI.StatusBarHeight-1);
	//Draw a line Beside the Toolssbar
	pWind->DrawLine(UI.ToolBarHeight, UI.ToolBarHeight, UI.ToolBarHeight, UI.height);	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearToolBar() const
{
	pWind->SetBrush(UI.ToolBarColor);
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::Clear2ndToolBar() const
{
	pWind->SetBrush(UI.ToolBarColor);
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.ToolBarHeight, UI.width - UI.StatusBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	ClearToolBar();   //Clears the toolbar before drawing
	Clear2ndToolBar(); 
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[PLY_ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_TODRAW] = "images\\MenuItems\\Menu_Switch.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(UI.ToolBarHeight+1, UI.ToolBarHeight+1, UI.width, UI.height - UI.StatusBarHeight-1);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(24, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.1), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawLine(Point P1, Point P2, bool selected) const 
{	color DrawingClr;
drawstyle style;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		else			
		DrawingClr =getCrntDrawColor();
	pWind->SetPen(DrawingClr,1);
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y);

}
void Output::DrawTri(Point P1, Point P2, Point P3 ,GfxInfo RectGfxInfo, bool selected) const
	{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y,P3.x, P3.y, style);
	
}



//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

