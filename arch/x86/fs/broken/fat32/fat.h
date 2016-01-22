struct fat32_bootsect{
	int jmp;
	int oem_ident;
	int bps;
	int npc;
	int rs;
	int fats;
	int ndentr;
	int ts;
	int mdt;
	int spf;
	int spt;
	int hs;
	int lasm;
};
struct fat32_ebr{
	int spf;
	int flags;
	int vn;
	int crd;
	int sn;
	int snb;
	int resv;
	int dn;
	int sig;
	int vid;
	int *bc;
	int *sig;
};
unsigned char FAT_table[512];
unsigned int fat_offset;
unsigned int fat_sector;
unsigned int ent_offset;
unsigned int table_value;
struct fat_dirent{
	char *name;
	int atr;
	int resv;
	int ctime;
	int time;
	int date;
	int la;
	int high16;
	int lmt;
	int lmd;
	int l16;
	int size;
};
int fat32_init(struct fat32_bootsect *bs,struct fat32_ebr *ebr);
int fat32_read(char *filename,char *buf);

