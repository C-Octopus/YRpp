/*
	Warheads
*/

#ifndef WARHEADTYPE_H
#define WARHEADTYPE_H

#include <AbstractTypeClass.h>

//forward declarations
class AnimTypeClass;
class ParticleTypeClass;
class VoxelAnimTypeClass;

class WarheadTypeClass : public AbstractTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(WarheadTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x75E080); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x75E0C0); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x75E2C0); }

	//Destructor
	virtual ~WarheadTypeClass()
		{ THISCALL(0x75D230); }

	//AbstractClass
	virtual void PointerExpired(void* p, bool bUnknown)
		{ PUSH_VAR8(bUnknown); PUSH_VAR32(p); THISCALL(0x75E440); }
	virtual eAbstractType WhatAmI()
		{ return abs_WarheadType; }
	virtual int Size()
		{ return sizeof(WarheadTypeClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x75DEC0); }

	//AbstractTypeClass
	virtual bool LoadFromINI(CCINIClass* ini)
		{ PUSH_VAR32(ini); THISCALL(0x75D3A0); }

	//Constructor
	WarheadTypeClass(const char* id):AbstractTypeClass(false)
		{ PUSH_VAR32(id); THISCALL(0x75CEC0); }

protected:
	WarheadTypeClass():AbstractTypeClass(false)
		{ }
	WarheadTypeClass(bool X):AbstractTypeClass(X)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(double,  Deform);

	PROPERTY_ARRAY(double, Verses, 0xB);
/*
	//MISTYPE BY WESTWOOD!
	protected: double Verses[0x0B]; //access using the Armor Type definitions
	public: double get_Verses(int ArmorType)
		{ return Verses[ArmorType]; }
				void set_Verses(int ArmorType, double value)
		{ Verses[ArmorType] = value; }
*/

	PROPERTY(double,  ProneDamage);
	PROPERTY(int,     DeformTreshold);

	PROPERTY_STRUCT(TypeList<AnimTypeClass*>, AnimList);

	PROPERTY(int,     InfDeath);
	PROPERTY(float,   CellSpread);
	PROPERTY(float,   CellInset);
	PROPERTY(float,   PercentAtMax);
	PROPERTY(bool,    CausesDelayKill);
	PROPERTY(int,     DelayKillFrames);
	PROPERTY(float,   DelayKillAtMax);
	PROPERTY(float,   CombatLightSize);
	PROPERTY(ParticleTypeClass*, Particle);
	PROPERTY(bool,    Wall);
	PROPERTY(bool,    WallAbsoluteDestroyer);
	PROPERTY(bool,    PenetratesBunker);
	PROPERTY(bool,    Wood);
	PROPERTY(bool,    Tiberium);
	PROPERTY(bool,    unknown_bool_149);
	PROPERTY(bool,    Sparky);
	PROPERTY(bool,    Sonic);
	PROPERTY(bool,    Fire);
	PROPERTY(bool,    Conventional);
	PROPERTY(bool,    Rocker);
	PROPERTY(bool,    DirectRocker);
	PROPERTY(bool,    Bright);
	PROPERTY(bool,    CLDisableRed);
	PROPERTY(bool,    CLDisableGreen);
	PROPERTY(bool,    CLDisableBlue);
	PROPERTY(bool,    EMEffect);
	PROPERTY(bool,    MindControl);
	PROPERTY(bool,    Poison);
	PROPERTY(bool,    IvanBomb);
	PROPERTY(bool,    ElectricAssault);
	PROPERTY(bool,    Parasite);
	PROPERTY(bool,    Temporal);
	PROPERTY(bool,    IsLocomotor);
	PROPERTY(_GUID,   Locomotor);
	PROPERTY(bool,    Airstrike);
	PROPERTY(bool,    Psychedelic);
	PROPERTY(bool,    BombDisarm);
	PROPERTY(int,     Paralyzes);
	PROPERTY(bool,    Culling);
	PROPERTY(bool,    MakesDisguise);
	PROPERTY(bool,    NukeMaker);
	PROPERTY(bool,    Radiation);
	PROPERTY(bool,    PsychicDamage);
	PROPERTY(bool,    AffectsAllies);
	PROPERTY(bool,    Bullets);
	PROPERTY(bool,    Veinhole);
	PROPERTY(int,     ShakeXlo);
	PROPERTY(int,     ShakeXhi);
	PROPERTY(int,     ShakeYlo);
	PROPERTY(int,     ShakeYhi);

	PROPERTY_STRUCT(TypeList<VoxelAnimTypeClass*>, DebrisTypes);
	PROPERTY_STRUCT(TypeList<int>, DebrisMaximums);

	PROPERTY(int,     MaxDebris);
	PROPERTY(int,     MinDebris);
	PROTECTED_PROPERTY(DWORD, unused_1CC); //???
};

#endif