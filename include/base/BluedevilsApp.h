#ifndef BLUEDEVILSAPP_H
#define BLUEDEVILSAPP_H

#include "MooseApp.h"

class BluedevilsApp;

template<>
InputParameters validParams<BluedevilsApp>();

class BluedevilsApp : public MooseApp
{
public:
  BluedevilsApp(InputParameters parameters);
  virtual ~BluedevilsApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* BLUEDEVILSAPP_H */
