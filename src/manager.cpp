#include "manager.h"
#include "constants.h"

Manager::Manager():
name_("Nieznany"),
preferred_style_(TacticStyle::POSSESSION) {}

Manager::Manager(const std::string& name, TacticStyle preferred_style)
: name_(name),
preferred_style_(preferred_style) {}

const std::string& Manager::name() const {
    return name_;
}

TacticStyle Manager::preferredStyle() const {
    return preferred_style_;
}

bool Manager::matchesStyle(TacticStyle tactic) const{
    return preferred_style_ == tactic;
}

double Manager::styleBonus(TacticStyle tactic) const{
    return matchesStyle(tactic) ? MANAGER_STYLE_BONUS : 1.0;
}

std::string Manager::styleLabel(TacticStyle style) {
    if (style == TacticStyle::ATTACKING){
        return "Ofensywna";
    }
    if (style == TacticStyle::DEFENSIVE){
        return "Defensywna";
    }
    if (style == TacticStyle::COUNTER){
        return "Kontra";
    }
    if (style == TacticStyle::PRESSING){
        return "Pressing";
    }    
        return "Posiadanie";

}

std::string Manager::styleDescription(TacticStyle style) {
    if (style == TacticStyle::ATTACKING){
        return "Duzo graczy w ataku, ryzyko z tylu.";
    }
    if (style == TacticStyle::DEFENSIVE){
        return "Gleboki blok, malo goli po obu stronach.";
    }
    if (style == TacticStyle::COUNTER){
        return "Cierpliwa obrona i szybkie przejscie do ataku.";
    }
    if (style == TacticStyle::PRESSING){
        return "Wysoki odbior, duze zuzycie kondycji.";
    }    
        return "Kontrola pilki, wymaga wysokiej techniki.";

}
