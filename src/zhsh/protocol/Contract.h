//------------------------------------------------------------------------------
/*
 This file is part of zhshchaind: https://github.com/zhshchain/zhshchaind
 Copyright (c) 2016-2018 ZHSH Technology Co., Ltd.
 
	zhshchaind is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
 
	zhshchaind is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
 */
//==============================================================================

#ifndef RIPPLE_PROTOCOL_CONTRACT_H_INCLUDED
#define RIPPLE_PROTOCOL_CONTRACT_H_INCLUDED

#include <ripple/protocol/AccountID.h>
namespace ripple {

    class Contract
    {
    public:
        static AccountID calcNewAddress(AccountID sender, int nonce);
    private:
        Contract();
    };

}

#endif