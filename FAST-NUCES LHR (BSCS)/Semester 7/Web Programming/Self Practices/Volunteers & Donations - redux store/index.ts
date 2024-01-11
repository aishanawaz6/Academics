import khidmatDonationSlice  from "./khidmatDonationSlice.ts";
import { configureStore } from '@reduxjs/toolkit'
import khidmatVolunteerSlice from "./khidmatVolunteerSlice.ts";
export const GlobalStore = configureStore({
  reducer: {
    donationHistory: khidmatDonationSlice,
    volunteerHistory:khidmatVolunteerSlice,
  },
});

export type RootState = ReturnType<typeof GlobalStore.getState>;
export type AppDispatch = typeof GlobalStore.dispatch;