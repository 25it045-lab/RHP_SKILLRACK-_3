#include "codeforces.h"
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono_literals;
using namespace cf;

int main() {
    Blog announcement("Codeforces Round 1119 (Div. 3)");

    announcement << "Hello Codeforces!\n";
    announcement << "I am delighted to invite you to participate in " << Codeforces Round 1119 (Div. 3) << "!\n";
    announcement << "The problems were written and prepared by " << nik_exists << ".\n\n";

    announcement << ContestInfo {
        .start_time = Saturday, September 5, 2026 at 20:05UTC+5.5,
        .duration = 2h + 15min,
        .number_of_problems = 7,
        .subtasks = true // possibly not adjacent
    };

    announcement << RatingRules {
        .rated_for_rating_below = 1600,
        .unrated_registration_allowed = true,
        .trusted_max_rating_below = 1900,
        .trusted_min_rated_rounds = 5
    };

    announcement << JudgingRules {
        .scoring = codeforces::ICPC,
        .wrong_answer_penalty = 10min,
        .open_hacking_phase = 12h,
        .final_tests = after_open_hacks
    };

    auto is_cheater = [](User user) {
        // https://codeforces.com/blog/entry/133941
        if (user.used_ai_in_contest()) return true;
        if (user.discussed_problems_online_before_contest_end()) return true;
        if (user.violated_other_rules_im_too_lazy_to_list()) return true;
        return false;
    };

    for (auto user : get_users(2259)) {
        if (is_cheater(user)) user.send_to_cry_basement();
    }

    announcement << Acknowledgements {
        .coordinator = cry,
        .russian_translation = Vladosiya,
        .red_testers = {__baozii__, AksLolCoding, awesomeguy856, nifeshe},
        .golden_testers = {Arpa, Intellegent, Proof_by_QED, temporary1},
        .purple_testers = {Argentum47, Euclid73, Jteh, Lilypad, SpyrosAliv, nimoxide, omsincoconut, wakanda-forever, yse},
        .blue_testers = {CatsAreCool, Vladosiya, chromate00, fatespeaker, linearspace, reirugan, simplelife},
        .green_testers = {hannah12345},
        .codeforces_and_polygon = {KAN, MikeMirzayanov}
    };

    announcement << "\nBest of luck, and thank y'all so much for competing!\n";
}
