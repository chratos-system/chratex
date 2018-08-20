/**
 * Copyright (c) 2018 chratex developers (see AUTHORS)
 *
 * This file is part of chratex
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtest/gtest.h>
#include <wallet/wallet.hpp>
#include <utility/filesystem.hpp>

TEST(wallet, creating_new_wallet) {
  bool init;
  chratex::mdb_env environment(init, chratex::filesystem::unique_path());
  ASSERT_FALSE(init);
  auto transaction(chratex::transaction(environment, nullptr, true));
  auto wallet_store = chratex::wallet_store(transaction, "0");
}
