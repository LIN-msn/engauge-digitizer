/******************************************************************************************************
 * (C) 2020 markummitchell@github.com. This file is part of Engauge Digitizer, which is released      *
 * under GNU General Public License version 2 (GPLv2) or (at your option) any later version. See file *
 * LICENSE or go to gnu.org/licenses for details. Distribution requires prior written permission.     *
 ******************************************************************************************************/

#ifndef CENTIPEDE_SEGMENT_ABSTRACT_H
#define CENTIPEDE_SEGMENT_ABSTRACT_H

#include <QPointF>
#include "Transformation.h"

class QGraphicsItem;

/// Line segment along one of the two coordinate directions (X/T or Y/R).
/// Centipede instances are distinguished by coordinate direction, and implemented with either line or ellipse graphics item
class CentipedeSegmentAbstract
{
public:
  /// Constructor with individual coordinates
  CentipedeSegmentAbstract(const Transformation &transformation,
                           const QPointF &posCenterScreen,
                           double initialRadius);
  virtual ~CentipedeSegmentAbstract ();

  /// Return distance to closest endpoint
  virtual double distanceToClosestEndpoint (const QPointF &posScreen) const = 0;

  /// Expose graphics item for registering with scene
  virtual QGraphicsItem *graphicsItem () = 0;

  /// Update geometry to reflect cursor movement
  virtual void updateRadius (double radius) = 0;
  
protected:

  /// Initial radius of circle
  double initialRadius () const;

  /// Center of circle in screen coordinates
  QPointF posCenterScreen () const;

  /// Screen point for XT value of center in the increasing YR direction
  QPointF posScreenConstantXTHighYR (double radius) const;

  /// Screen point for XT value of center in the decreasing YR direction
  QPointF posScreenConstantXTLowYR (double radius) const;

  /// Screen point for YR value of center in the increasing XT direction
  QPointF posScreenConstantYRHighXT (double radius) const;

  /// Screen point for YR value of center in the decreasing XT direction
  QPointF posScreenConstantYRLowXT (double radius) const;
  
  /// Transformation which is static through the entire lifetime of the Centipede class instances
  Transformation transformation() const;
  
private:
  CentipedeSegmentAbstract();

  void generatePreviousAndNextPoints (double radius,
                                      int i,
                                      QPointF &posGraphPrevious,
                                      QPointF &posScreenPrevious,
                                      QPointF &posScreenNext) const;
  QPointF posScreenConstantXTForScaledYR (double radius,
                                          double scale) const;
  QPointF posScreenConstantYRForScaledXT (double radius,
                                          double scale) const;

  Transformation m_transformation;
  QPointF m_posCenterScreen;
  double m_initialRadius;
  
};

#endif // CENTIPEDE_SEGMENT_ABSTRACT_H