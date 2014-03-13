#pragma once
//#include "lilhelpers.h"
enum class Eitemtype  {
	NOTHING, MOB_SKEL, MOB_KOBBY, MOB_GOLEM, MOB_CUEB, MOB_IMP, MOB_BAT,
	MOB_FIRESKEL, MOB_CUEBOBJ, MOB_ESR, MOB_ESRSHIELD, MOB_BROOM, MOB_BROOMSWORD, MOB_TZIKEN,
	ITEM_GEM, ITEM_GOLD, ITEM_BATTERY, ITEM_SHIELD, ITEM_STOPWATCH, ITEM_SWORD, ITEM_MEDPACK, 
	ITEM_KEY, ITEM_JUNK, ITEM_LAVA,
	DEAD_SKEL, DEAD_KOBBY, DEAD_GOLEM, DEAD_CUEB, DEAD_IMP, DEAD_BAT,
	DEAD_RABBIT, DEAD_BROOM};

//There is one instance of mob_archetype per monster
struct item_archetype {
	string name;
	Eitemtype type;
	Eitemtype deadoneofthem;
	SDL_Texture* sprite;
	
	bool ismob;
	bool rangedattacker;
	int optimumrangeddistance;
	int maxhp;
	

	int damagetheydeal = 1;
	bool lavadamagesthem = true;
	bool fitsinvacuum = true;
	bool blownitemdamagesthem = true;
	
	item_archetype(){
		std::cout << "wtf";
	}

	item_archetype(
		string _name,
		Eitemtype _type,
		Eitemtype _corpse,
		SDL_Texture* _sprite,
		
		bool _ismob,
		bool _rangedattacker,
		int _optimumrangeddistance,
		int _maxhp,

		int _damdeal,
		bool _damlava,
		bool _fitvac, 
		bool _blown) :

		name(_name),
		type(_type),
		deadoneofthem(_corpse), 
		sprite(_sprite),
		
		ismob(_ismob), 
		rangedattacker(_rangedattacker),
		optimumrangeddistance(_optimumrangeddistance),
		maxhp(_maxhp),
		
		damagetheydeal(_damdeal),
		lavadamagesthem(_damlava),
		fitsinvacuum(_fitvac),
		blownitemdamagesthem(_blown){
	}

	
};

 enum class EBehaviour { BEHAVIOUR_STATIC, BEHAVIOUR_WANDERING, BEHAVIOUR_CHASING };

//vector<item_archetype> item_archetype_list;

 unordered_map<Eitemtype, item_archetype> dicoarchetype;

struct item_instance {
	item_archetype* type;
	EBehaviour behaviour=EBehaviour::BEHAVIOUR_WANDERING;
	int posx, posy;
	int hp;

	bool invacuum = false;
	

	item_instance(Eitemtype _type, int _x, int _y
		){
		posx = _x, posy = _y;
		type = &dicoarchetype[_type];
		hp = type->maxhp;
		
	}

};


//name, type, deadtype, sprite, ismob?, israngedattacker?, optdist, maxhp, damdealt, dambylava?, fitvac?, takes ranged dam
void setupitems(){

	//item_archetype f = { "skelington", Eitemtype::MOB_SKEL, Eitemtype::DEAD_SKEL, dicosprite.at("skel"), true, false, 0, 1, 1, false, true, true };
	//item_archetype* ff = &f;
	//dicoarchetype.insert(Eitemtype::DEAD_BAT,)

	dicoarchetype.insert(pair<Eitemtype,item_archetype>( Eitemtype::MOB_SKEL,
	{ "skelington", Eitemtype::MOB_SKEL, Eitemtype::DEAD_SKEL, dicosprite.at("skel"), true, false, 0, 1, 1, false, true, true }));
	
	
	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::MOB_KOBBY,
	{ "kobby bomber", Eitemtype::MOB_KOBBY, Eitemtype::DEAD_KOBBY, dicosprite.at("kobby bomber"), true, true, 5, 1,1,true,true,true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::MOB_GOLEM,
	{ "caek golem", Eitemtype::MOB_GOLEM, Eitemtype::DEAD_GOLEM, dicosprite.at("cake golem"), true, false, 0, 1, 1, true, false, true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::MOB_CUEB,
	{ "gelatinous cueb", Eitemtype::MOB_CUEB, Eitemtype::DEAD_CUEB, dicosprite.at("gelatinous cueb"), true, false, 0, 1, 1, true, false, true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::MOB_IMP,
	{ "fier imp", Eitemtype::MOB_IMP, Eitemtype::DEAD_IMP, dicosprite.at("fire imp"), true, false, 0, 1, 1, false, true, true }));
	
	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::MOB_BAT,
	{ "vampier bat", Eitemtype::MOB_BAT, Eitemtype::DEAD_BAT, dicosprite.at("bat"), true, false, 0, 1, 1, false, true, true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::MOB_SKEL,
	{ "fier skelington", Eitemtype::MOB_FIRESKEL,Eitemtype::DEAD_SKEL, dicosprite.at("fire skel"), true, false, 0, 1, 2, false, true, true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::MOB_CUEBOBJ,
	{ "fat cueb", Eitemtype::MOB_CUEBOBJ, Eitemtype::DEAD_CUEB, dicosprite.at("cueb object"), true, false, 0, 1, 1, true, false, true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::MOB_ESR,
	{ "Extra Space Rabbit", Eitemtype::MOB_ESR, Eitemtype::DEAD_RABBIT, dicosprite.at("esr"), true, true, 3, 1, 1, true, true, true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::MOB_ESRSHIELD,
	{ "Shielded Rabbit", Eitemtype::MOB_ESRSHIELD, Eitemtype::DEAD_RABBIT, dicosprite.at("esr shield"), true, true, 3, 1, 1, true, true, false }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::MOB_BROOM,
	{ "Princess Broom", Eitemtype::MOB_BROOM, Eitemtype::DEAD_BROOM, dicosprite.at("broom"), true, false, 0, 3, 0, true, true, true }));
	

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::MOB_BROOM,
	{ "Battle broom", Eitemtype::MOB_BROOMSWORD, Eitemtype::DEAD_BROOM, dicosprite.at("broom sword"), true, false, 0, 3, 1, true, true, true }));
	
	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::MOB_TZIKEN,
	{ "Golden Tziken", Eitemtype::MOB_TZIKEN, Eitemtype::NOTHING, dicosprite.at("golden tziken"), true, false, 0, 3, 0, true, true, true }));

	//ITEMS need to change item and mob numbers maybe just item BATTERY TO JUNK

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::ITEM_GEM,
	{ "shineh gemz", Eitemtype::ITEM_GEM, Eitemtype::NOTHING, dicosprite.at("gems"), false, false, 0, 0, 0, false, true, true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::ITEM_GOLD,
	{ "gold barz", Eitemtype::ITEM_GOLD, Eitemtype::NOTHING, dicosprite.at("gold"), false, false, 0, 0, 0, false, true, true }));
	
	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::ITEM_KEY,
	{ "key", Eitemtype::ITEM_KEY, Eitemtype::NOTHING, dicosprite.at("key"), false, false, 0, 0, 0, false, true, true }));
	
	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::ITEM_BATTERY,
	{ "batterehs", Eitemtype::ITEM_BATTERY, Eitemtype::NOTHING, dicosprite.at("batteries"), false, false, 0, 0, 0, false, true, true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::ITEM_SHIELD,
	{ "Aegis", Eitemtype::ITEM_SHIELD, Eitemtype::NOTHING, dicosprite.at("shield"), false, false, 0, 0, 0, false, true, true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::ITEM_STOPWATCH,
	{ "stasis device", Eitemtype::ITEM_STOPWATCH, Eitemtype::NOTHING, dicosprite.at("stopwatch"), false, false, 0, 0, 0, false, true, true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::ITEM_SWORD,
	{ "Curtana", Eitemtype::ITEM_SWORD, Eitemtype::NOTHING, dicosprite.at("sword"), false, false, 0, 0, 0, false, true, true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::ITEM_MEDPACK,
	{ "medpack", Eitemtype::ITEM_MEDPACK, Eitemtype::NOTHING, dicosprite.at("medpack"), false, false, 0, 0, 0, false, true, true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::ITEM_JUNK,
	{ "junk", Eitemtype::ITEM_JUNK, Eitemtype::NOTHING, dicosprite.at("junk"), false, false, 0, 0, 0, false, true, true }));


	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::ITEM_LAVA,
	{ "lava", Eitemtype::ITEM_LAVA, Eitemtype::NOTHING, dicosprite.at("lava"), false, false, 0, 0, 0, false, true, true }));

	//mobs

	
	//corpses - items

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::DEAD_SKEL,
	{ "pile of boenz", Eitemtype::DEAD_SKEL, Eitemtype::NOTHING, dicosprite.at("dead skel"), false, false, 0, 0, 0, false, true, true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::DEAD_KOBBY,
	{ "ex-kobby", Eitemtype::DEAD_KOBBY, Eitemtype::NOTHING, dicosprite.at("kobby dead"), false, false, 0, 0, 0, false, true, true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::DEAD_GOLEM,
	{ "sad crumbs", Eitemtype::DEAD_GOLEM, Eitemtype::NOTHING, dicosprite.at("dead cake"), false, false, 0, 0, 0, false, false, true }));

	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::DEAD_CUEB,
	{ "sticky mess", Eitemtype::DEAD_CUEB, Eitemtype::NOTHING, dicosprite.at("dead cueb"), false, false, 0, 0, 0, false, false, true }));


	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::DEAD_IMP,
	{ "smokin' hot corpse", Eitemtype::DEAD_IMP, Eitemtype::NOTHING, dicosprite.at("dead imp"), false, false, 0, 0, 0, false, true, true }));


	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::DEAD_BAT,
	{ "effed-up lil' bat body", Eitemtype::DEAD_BAT, Eitemtype::NOTHING, dicosprite.at("dead bat"), false, false, 0, 0, 0, false, true, true }));


	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::DEAD_RABBIT,
	{ "extra dead rabbit", Eitemtype::DEAD_RABBIT, Eitemtype::NOTHING, dicosprite.at("esr dead"), false, false, 0, 0, 0, false, true, true }));


	dicoarchetype.insert(pair<Eitemtype, item_archetype>(Eitemtype::DEAD_BROOM,
	{ "tomb of broom", Eitemtype::DEAD_BROOM, Eitemtype::NOTHING, dicosprite.at("grave"), false, false, 0, 0, 0, false, true, true }));

	

}

