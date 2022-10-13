#pragma once
namespace Hooks
{
	void install();

	class ModActorValueHook
	{
	public:
		static void Hook()
		{
			auto hook_addr = REL::RelocationID{ 37522, 38467 }.address() + 0x14;
			SKSE::AllocTrampoline(14);
			_SetActorValueModifiers = SKSE::GetTrampoline().write_call<5>(hook_addr, (uintptr_t)&DamageActorValue);

			//_DamageTargetActorValue = trampoline.write_call<5>(REL::ID(36345).address() + 0x11D, DamageTargetActorValue);  //damage from another actor
		}

	private:
		static void DamageActorValue(RE::Actor* actor, RE::ACTOR_VALUE_MODIFIER avModifier, RE::ActorValue actorValue, float value);
		static inline REL::Relocation<decltype(DamageActorValue)> _SetActorValueModifiers;

		//static void DamageTargetActorValue(RE::Actor* damageTarget, RE::ACTOR_VALUE_MODIFIER avModifier, RE::ActorValue actorValue, float value, RE::TESObjectREFR* damageSource);
	};

}
