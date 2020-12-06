/******************************************************************************************************
 * (C) 2020 markummitchell@github.com. This file is part of Engauge Digitizer, which is released      *
 * under GNU General Public License version 2 (GPLv2) or (at your option) any later version. See file *
 * LICENSE or go to gnu.org/licenses for details. Distribution requires prior written permission.     *
 ******************************************************************************************************/

#ifndef CENTIPEDE_STATE_CONTEXT_H
#define CENTIPEDE_STATE_CONTEXT_H

#include "CentipedeState.h"
#include <QPointF>
#include <QVector>

class CentipedeStateAbstractBase;

/// State context class for tracking the steps involved in creating centipedes in preparation
/// for creating a guideline
class CentipedeStateContext
{
public:
  /// Single constructor
  CentipedeStateContext ();
  virtual ~CentipedeStateContext ();

  virtual void handleKeyPress (Qt::Key key,
                               bool atLeastOneSelectedItem);
  virtual void handleMouseMove (QPointF posScreen);
  virtual void handleMousePress (QPointF posScreen);
  virtual void handleMouseRelease (QPointF posScreen);

  /// Initiate state transition to be performed later, when CentipedeState is off the stack
  void requestDelayedStateTransition (CentipedeState centipedeState);
  
  /// Perform immediate state transition for immediate action. Called when states are off the stack
  void requestImmediateStateTransition (CentipedeState centipedeState);
  
private:

  void completeRequestedStateTransitionIfExists ();

  QVector<CentipedeStateAbstractBase*> m_states;
  CentipedeState m_currentState;
  CentipedeState m_requestedState; // Same as m_currentState until requestDelayedStateTransition is called
};

#endif // CENTIPEDE_STATE_CONTEXT_H