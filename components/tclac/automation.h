#pragma once

#include "esphome/core/automation.h"
#include "tclac.h"

namespace esphome {
namespace tclac {

// Aktionsmuster: Veränderung der vertikalen Fixierung der Klappe
template<typename... Ts> class VerticalAirflowAction : public Action<Ts...> {
 public:
  VerticalAirflowAction(tclacClimate *parent) : parent_(parent) {}
  TEMPLATABLE_VALUE(AirflowVerticalDirection, direction)
  void play(Ts... x) { this->parent_->set_vertical_airflow(this->direction_.value(x...)); }

 protected:
  tclacClimate *parent_;
};

// Aktionsmuster: Änderung der horizontalen Klappenfixierung
template<typename... Ts> class HorizontalAirflowAction : public Action<Ts...> {
 public:
  HorizontalAirflowAction(tclacClimate *parent) : parent_(parent) {}
  TEMPLATABLE_VALUE(AirflowHorizontalDirection, direction)
  void play(Ts... x) { this->parent_->set_horizontal_airflow(this->direction_.value(x...)); }

 protected:
  tclacClimate *parent_;
};

// Aktionsmuster: Änderung des vertikalen Schwenkmodus der Klappe
template<typename... Ts> class VerticalSwingDirectionAction : public Action<Ts...> {
 public:
  VerticalSwingDirectionAction(tclacClimate *parent) : parent_(parent) {}
  TEMPLATABLE_VALUE(VerticalSwingDirection, direction)
  void play(Ts... x) { this->parent_->set_vertical_swing_direction(this->direction_.value(x...)); }

 protected:
  tclacClimate *parent_;
};

// Aktionsmuster: Änderung des horizontalen Klappenschwenkmodus
template<typename... Ts> class HorizontalSwingDirectionAction : public Action<Ts...> {
 public:
  HorizontalSwingDirectionAction(tclacClimate *parent) : parent_(parent) {}
  TEMPLATABLE_VALUE(HorizontalSwingDirection, direction)
  void play(Ts... x) { this->parent_->set_horizontal_swing_direction(this->direction_.value(x...)); }

 protected:
  tclacClimate *parent_;
};

// Aktionsmuster: Einschalten des Displays
template<typename... Ts> class DisplayOnAction : public Action<Ts...> {
 public:
  DisplayOnAction(tclacClimate *parent) : parent_(parent) {}
  void play(Ts... x) { this->parent_->set_display_state(true); }

 protected:
  tclacClimate *parent_;
};

// Aktionsmuster: Ausschalten des Displays
template<typename... Ts> class DisplayOffAction : public Action<Ts...> {
 public:
  DisplayOffAction(tclacClimate *parent) : parent_(parent) {}
  void play(Ts... x) { this->parent_->set_display_state(false); }

 protected:
  tclacClimate *parent_;
};

// Aktionsmuster: Einschalten des Beepers
template<typename... Ts> class BeeperOnAction : public Action<Ts...> {
 public:
  BeeperOnAction(tclacClimate *parent) : parent_(parent) {}
  void play(Ts... x) { this->parent_->set_beeper_state(true); }

 protected:
  tclacClimate *parent_;
};

// Aktionsmuster: Ausschalten des Beepers
template<typename... Ts> class BeeperOffAction : public Action<Ts...> {
 public:
  BeeperOffAction(tclacClimate *parent) : parent_(parent) {}
  void play(Ts... x) { this->parent_->set_beeper_state(false); }

 protected:
  tclacClimate *parent_;
};

// Aktionsmuster: Einschalten der Modulanzeige
template<typename... Ts> class ModuleDisplayOnAction : public Action<Ts...> {
 public:
  ModuleDisplayOnAction(tclacClimate *parent) : parent_(parent) {}
  void play(Ts... x) { this->parent_->set_module_display_state(true); }

 protected:
  tclacClimate *parent_;
};

// Aktionsmuster: Ausschalten der Modulanzeige
template<typename... Ts> class ModuleDisplayOffAction : public Action<Ts...> {
 public:
  ModuleDisplayOffAction(tclacClimate *parent) : parent_(parent) {}
  void play(Ts... x) { this->parent_->set_module_display_state(false); }

 protected:
  tclacClimate *parent_;
};

// Aktionsvorlage: Durchsetzung der Einstellungen aktivieren
template<typename... Ts> class ForceOnAction : public Action<Ts...> {
 public:
  ForceOnAction(tclacClimate *parent) : parent_(parent) {}
  void play(Ts... x) { this->parent_->set_force_mode_state(true); }

 protected:
  tclacClimate *parent_;
};

// Aktionsvorlage: Durchsetzung der Einstellungen ausschalten
template<typename... Ts> class ForceOffAction : public Action<Ts...> {
 public:
  ForceOffAction(tclacClimate *parent) : parent_(parent) {}
  void play(Ts... x) { this->parent_->set_force_mode_state(false); }

 protected:
  tclacClimate *parent_;
};

}  // namespace tclac
}  // namespace esphome
