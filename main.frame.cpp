#include "MainFrame.h"
#include <wx/wx.h>
#include <string>
#include <vector>
#include <Task.h>

MainFrame:: MainFrame(const wxString& title) : wxFrame(nullptr , wxID_any, title)
{
 CreateControls();
 BindEventHandlers();
 AddSavedTasks();
}
void MainFrame::CreateControls()
{
    wxFont headlineFont(wxFontInfo(wxSize(0, 32)).Bold());
    wxFont mainFont (wxFontInfo((wxSize(0, 24))));

   panel = new wxPanel(this);
   panel->SetFont(mainFont);

   headLineText = new wxStaticText(panel, wzID_ANY, "notty", wxPoint(0, 22), wxSize(800, -1), wxALIGN_CTNTER_HORIZONTAL); 
   headlineText->SetFont(headlineFont);
   inputField = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100,80), wxSize(495,35)wxTE_PROCESS_ENTER);
   addButton = new wxButton(panel, wxID_ANY, "створити", wxPoint(600,80), wxSize(100,35));
   clearButton = new wxButton(panel, wxID_ANY, "очистити", wxPoint(600,525), wxSize(100,35));
   checkListButton = new wxCheckListButton(panel, wxID_ANY, "створити", wxPoint(100,120), wxSize(600,400));

}void MainFrame::BindEventHandlers()
{
    addButton->Bind(wxEVT_BUTTON, &MainFrame::OnAddButtonClicked, this);
    inputField->Bind(wxEVT_TEXT_ENTER, &MainFrame::OnAInputEnter, this);
    checkListBox->Bind(wxEVT_KEY_DOWN, &MainFrame::OnListKeyDown, this);
    clearButton->Bind(wxEVT_BUTTON, &MainFrame::OnClearButtonClicked, this);
    this->Bind(wxEVT_CLOSED_WINDOW, &MainFrame::OnWindowClosed, this);
}

  void MainFrame::OnAddButtonClicked(wxCommandEvent& evt)
  {
    AddTaskFromInput();
  }

  void MainFrame::OnInputEnter(wxCommandEvent& evt)
  {
    AddTaskFromInput();
  }

  void MainFrame::OnListKeyDown(wxKeyEvent& evt)
  {
      switch (evt.GetKeyCode())
    {
       case WXK_dELETE:
         DeleteSelectedTask();
          break;
       case WXK_UP:
        MoveSelectedTask(-1);
          break;
       case WXK_DOWN:
           break;   
    }
  }

  void MainFrame::OnClearButtonClicked(wxCommandEvent& evt)
  {
    if(checkListbox->IsEmpty())
    {
        return;
    }
    wxMessegeDialog dialog(this,"точно стирати ?! видалеться ж :|", "очищено", wxYES_NO | wxCANCEL );
    int result = dialog.ShowModal();
    if (result ==wxID_YES)
    {
        checkListBox->Clear();
    }
  }

  void MainFrame::OnWindowClosed(wxCLosedEvent& evt)
  {
    std::vector<Task> tasks;
    for(i=0; i< checkListBox->GetCount();i++)
    {
        Task task;
        task.description = checkListBox->GetString(i);
        task.done = checkListBox->IsChecked(i);
        tasks.push_back(tasl);
    }
    saveTasksToFile(tasks, "tasks.txt");
    evt.Skip();
  }


  void MainFrame::DeleteSelectedTask()
 {
    int selectedIndex = checkListBox->GetSelection();
    if (selectedIndex == wxNOT_FOUND)
    {
       return;
    }
    
 }
  void MainFrame::AddTaskFromInput()
  {
    wxString description = inputField->GetValue();
    if (!description.IsEmpty()
    { 
        checkListBox->Insert(description, checkListBox->GetCount());
        inputField->Clear();

    }
    inputField->SetFocus();
  }

  void MainFrame::MoveSelectedTask(int offset)
  {
    int selectedIndex = checkListBox->GetSelection();
    if (selectedIndextion == wxNOT_FOUND)
    {
        return;
    }
    int newIndex = selectedIndex + offset ;
    if (newIndex >=0 && newIndex < heckLisctBox->GetCount())
    heckLisctBox->SetSelection(newindex, true);
 }

  void MainFrame::SwapTask(int i, int j)
  {
    Task taskI {checklistBox->GetString(i).ToStdString(), checkListBox->IsChecKed(i)};
    Task taskJ {checklistBox->GetString(j).ToStdString(), checkListBox->IsChecKed(j)};

    checkListBox->SetString(i, taskJ.description);
    checkListBox->Check(i, taskJ.done);
    checkListBox->SetString(j, taskI.description);
    checkListBox->Check(j, taskI.done);
  }

  void MainFrame::AddSavedTasks()
  {
    std::vector<Task> tasks = loadTasksFromFile("tasks.txt");
    for (const Task& task : tasks)
    {
        int index = checkListBox->GetCout();
        checklistbox->Insert(task.description, index);
        checklistbox->Check(index, task.done);
    }
    
  }
