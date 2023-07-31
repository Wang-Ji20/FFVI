//===------------------------------------------===
// ffvi 2023
//
// Identification: include\model\entity.hh
//
// Author: Ji Wang <jiwangcdi@gmail.com>
//
//===------------------------------------------===

#pragma once

#include <memory>
#include <stdexcept>
#include <string>

namespace ffvi {

/// The Entity class is the base class for all entities, including the player
/// characters and enemies.
class Entity {
private:
  int healthpoint_;
  int manapoint_;
  int defense_;
  int attack_;
  /// Determines the rate at which the ATB gauge fills.
  int agility_;
  /// Determines HP-related effects, e.g. the chance to survive against death
  /// attacks, the amount they are healed by regen, the amount of damage dealt
  /// by poison, sap, and HP leak, and the amount of healing.
  int stamina_;
  /// magic attack.
  int magic_;
  ///  Determines the chance to block a physical attack against the party member
  ///  or enemy.
  int evasion_;
  int magicEvasion_;
  int magicDefense_;
  /// Determines the chance to hit a target with a physical attack.
  int hitRate_;
  /// Determines the chance to hit a critical hit.
  int critical_;

  class EntityBuilder {
  public:
    constexpr static int kInvalidStat = -1;

    EntityBuilder() = default;

    static inline auto IsInvalid(int stat) -> bool {
      return stat == kInvalidStat;
    }

    inline auto SetHealthpoint(int healthpoint) -> EntityBuilder & {
      healthpoint_ = healthpoint;
      return *this;
    }

    inline auto SetManapoint(int manapoint) -> EntityBuilder & {
      manapoint_ = manapoint;
      return *this;
    }

    inline auto SetDefense(int defense) -> EntityBuilder & {
      defense_ = defense;
      return *this;
    }

    inline auto SetAttack(int attack) -> EntityBuilder & {
      attack_ = attack;
      return *this;
    }

    inline auto SetAgility(int agility) -> EntityBuilder & {
      agility_ = agility;
      return *this;
    }

    inline auto SetStamina(int stamina) -> EntityBuilder & {
      stamina_ = stamina;
      return *this;
    }

    inline auto SetMagic(int magic) -> EntityBuilder & {
      magic_ = magic;
      return *this;
    }

    inline auto SetEvasion(int evasion) -> EntityBuilder & {
      evasion_ = evasion;
      return *this;
    }

    inline auto SetMagicEvasion(int magicEvasion) -> EntityBuilder & {
      magicEvasion_ = magicEvasion;
      return *this;
    }

    inline auto SetMagicDefense(int magicDefense) -> EntityBuilder & {
      magicDefense_ = magicDefense;
      return *this;
    }

    inline auto SetHitRate(int hitRate) -> EntityBuilder & {
      hitRate_ = hitRate;
      return *this;
    }

    inline auto SetCritical(int critical) -> EntityBuilder & {
      critical_ = critical;
      return *this;
    }

    inline auto FromPrototype(const Entity &entity) -> EntityBuilder & {
      healthpoint_ = entity.healthpoint_;
      manapoint_ = entity.manapoint_;
      defense_ = entity.defense_;
      attack_ = entity.attack_;
      agility_ = entity.agility_;
      stamina_ = entity.stamina_;
      magic_ = entity.magic_;
      evasion_ = entity.evasion_;
      magicEvasion_ = entity.magicEvasion_;
      magicDefense_ = entity.magicDefense_;
      hitRate_ = entity.hitRate_;
      critical_ = entity.critical_;
      return *this;
    }

    [[nodiscard("you cannot leave a newly created entity alone")]] auto
    Build() const -> std::unique_ptr<Entity> {
      auto entity_ = std::make_unique<Entity>();
      std::string errorMessage;

      if (IsInvalid(healthpoint_)) {
        errorMessage += "healthpoint is not set\n";
      }
      entity_->healthpoint_ = healthpoint_;

      if (IsInvalid(kInvalidStat)) {
        errorMessage += "manapoint is not set\n";
      }
      entity_->manapoint_ = manapoint_;

      if (IsInvalid(defense_)) {
        errorMessage += "defense is not set\n";
      }
      entity_->defense_ = defense_;

      if (IsInvalid(attack_)) {
        errorMessage += "attack is not set\n";
      }
      entity_->attack_ = attack_;

      if (IsInvalid(agility_)) {
        errorMessage += "agility is not set\n";
      }
      entity_->agility_ = agility_;

      if (IsInvalid(stamina_)) {
        errorMessage += "stamina is not set\n";
      }
      entity_->stamina_ = stamina_;

      if (IsInvalid(magic_)) {
        errorMessage += "magic is not set\n";
      }
      entity_->magic_ = magic_;

      if (IsInvalid(evasion_)) {
        errorMessage += "evasion is not set\n";
      }
      entity_->evasion_ = evasion_;

      if (IsInvalid(magicEvasion_)) {
        errorMessage += "magicEvasion is not set\n";
      }
      entity_->magicEvasion_ = magicEvasion_;

      if (IsInvalid(magicDefense_)) {
        errorMessage += "magicDefense is not set\n";
      }
      entity_->magicDefense_ = magicDefense_;

      if (IsInvalid(hitRate_)) {
        errorMessage += "hitRate is not set\n";
      }
      entity_->hitRate_ = hitRate_;

      if (IsInvalid(critical_)) {
        errorMessage += "critical is not set\n";
      }
      entity_->critical_ = critical_;

      if (!errorMessage.empty()) {
        throw std::invalid_argument(errorMessage);
      }

      return std::move(entity_);
    }

  private:
    int healthpoint_ = kInvalidStat;
    int manapoint_ = kInvalidStat;
    int defense_ = kInvalidStat;
    int attack_ = kInvalidStat;
    int agility_ = kInvalidStat;
    int stamina_ = kInvalidStat;
    int magic_ = kInvalidStat;
    int evasion_ = kInvalidStat;
    int magicEvasion_ = kInvalidStat;
    int magicDefense_ = kInvalidStat;
    int hitRate_ = kInvalidStat;
    int critical_ = kInvalidStat;
  };
};

} // namespace ffvi
