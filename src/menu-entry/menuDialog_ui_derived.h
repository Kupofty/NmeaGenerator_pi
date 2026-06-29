#ifndef __menuDialog_ui_derived__
#define __menuDialog_ui_derived__

#include "menuDialog_ui_base.h"

enum class DialogAction
{
  None = 0,
  UpdateOwnShip = 1,
  UpdateAisTarget = 2,
  AddAisTarget = 3,
  RemoveLastAisTarget = 4,
  ClearAisTargets = 5
};

class DialogMenuEntry : public DialogMenuEntryBase
{
  public:
    DialogMenuEntry( wxWindow* parent );
    DialogAction m_action = DialogAction::None;

  protected:
    void OnButtonClick_UpdateOwnShipPosition( wxCommandEvent& event ) override;
    void OnButtonClick_UpdateAisTargetPosition( wxCommandEvent& event ) override;
    void OnButtonClick_AddAisTarget( wxCommandEvent& event ) override;
    void OnButtonClick_RemoveLastAisTargets( wxCommandEvent& event ) override;
    void OnButtonClick_ClearAisTargets( wxCommandEvent& event) override;
};

#endif // __menuDialog_ui_derived__
