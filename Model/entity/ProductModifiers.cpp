#include "ProductModifiers.h"

int ProductModifiers::getPMId() const { return pmId; }
int ProductModifiers::getProdId() const { return prodId; }
int ProductModifiers::getModId() const { return modId; }

void ProductModifiers::setPMId(int newPMId) { pmId = newPMId; }
void ProductModifiers::setProdId(int newProdId) { prodId = newProdId; }
void ProductModifiers::setModId(int newModId) { modId = newModId; }