#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);
bool App::OnInit()
{
    MainFrame*mainFrame("notty");
    mainFrame->SetClientSize(800,600);
    mainFrame->Center();
    mainframe->Show();
    return false;
}
