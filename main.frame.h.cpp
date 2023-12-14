#pragma once
#include <wx/wx.h>
class MainFrame
{
 public:
 MainFrame(const wxString& title);
 private:
  void CreateControls();
  void BindEventHandlers();
  void OnAddButtonClicked(wxCommandEvent& evt);
  void OnInputEnter(wxCommandEvent& evt);
  void OnListKeyDown(wxKeyEvent& evt);
  void OnClearButtonClicked(wxCommandEvent& evt);
  void OnWindowClosed(wxCLosedEvent& evt);

  void DeleteSelectedTask();
  void AddTaskFromInput();
  void MoveSelectedTask(int offset);
  void SwapTask(int i, int j);

  void AddSavedTasks();

 wxPanel* panel;
 wxStaticText* headdLineText;
 wxButton* addButton;
 wxCheckListBox* checkListBox;
 wxButton* clearButton;


}
